//
// Created by Maksim Podkorytov on 11/20/15.
//

#include "GLTriangle.h"

#include <cmath>
#include <vector>

static GLuint loadShader (GLenum shader_type, const char *const source);

void GLTriangle::init() {
    GLuint vertex_shader = loadShader(GL_VERTEX_SHADER, v_shader);
    GLuint fragment_shader = loadShader(GL_FRAGMENT_SHADER, p_shader);
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glBindAttribLocation(program, 0, "vPosition");
    glLinkProgram(program);
    m_programObject = program;
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void GLTriangle::draw() {
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(m_programObject);

    const GLfloat rad = .5 + .25 * cos (time / 60.);

    const std::vector<GLfloat> vertices = [rad]
    {
        std::vector<GLfloat> v;
        const size_t total_vertices = 100;
        const float basic_angle = 2. * M_PI / total_vertices;
        for (size_t i = 0; i < total_vertices; ++i)
        {
            v.push_back(rad * (GLfloat) cos (basic_angle * i));
            v.push_back(rad * (GLfloat) sin (basic_angle * i));
            v.push_back(0);
        }
        return v;
    } ();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices.data());
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_LINE_LOOP, 0, vertices.size () / 3);
    ++time;
}

void GLTriangle::resizeView(int i, int i1) {
    width = i;
    height = i1;
    glViewport(0, 0, width, height);
}

static GLuint loadShader (GLenum shader_type, const GLchar * source)
{
    GLuint shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    return shader;
}