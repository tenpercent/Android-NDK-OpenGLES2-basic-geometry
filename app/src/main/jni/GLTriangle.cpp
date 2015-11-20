//
// Created by Maksim Podkorytov on 11/20/15.
//

#include "GLTriangle.h"

#include <cmath>

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

    const GLfloat vertices[] = {
             rad1 * cos(freq1 * time + phase1), rad1 * sin(freq1 * time + phase1), 0,
             rad2 * cos(freq2 * time + phase2), rad2 * sin(freq2 * time + phase2), 0,
             0,                                 0,                                 0
    };
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, vertices);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
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