package com.example.tenpercent.ndkopengles2triangle;

import android.app.Activity;
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MainActivity extends Activity {
    private GLSurfaceView m_view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        m_view = new TriangleView(getApplication());
        setContentView(m_view);
    }

    @Override
    protected void onPause ()
    {
        super.onPause();
        m_view.onPause();
    }

    @Override
    protected void onResume ()
    {
        super.onResume();
        m_view.onResume();
    }
}

class TriangleView extends GLSurfaceView
{
    GLSurfaceView.Renderer m_renderer;
    public TriangleView(Context context) {
        super(context);
        setEGLContextClientVersion(2);
        m_renderer = new TriangleRenderer();
        setRenderer(m_renderer);
    }
}

class TriangleRenderer implements GLSurfaceView.Renderer
{
    NativeWrapper wrapper;
    @Override
    public void onSurfaceCreated(GL10 gl10, EGLConfig eglConfig) {
        wrapper.nativeInit();
    }

    @Override
    public void onSurfaceChanged(GL10 gl10, int w, int h) {
        wrapper.nativeResize(w, h);
    }

    @Override
    public void onDrawFrame(GL10 gl10) {
        wrapper.nativeDraw();
    }
}

class NativeWrapper
{
    public native static void nativeInit ();
    public native static void nativeResize (int w, int h);
    public native static void nativeDraw ();

    static
    {
        System.loadLibrary("render_triangle");
    }
}
