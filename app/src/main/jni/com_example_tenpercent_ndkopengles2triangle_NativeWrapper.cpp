#include "com_example_tenpercent_ndkopengles2triangle_NativeWrapper.h"
#include "GLTriangle.h"

static GLTriangle triangle;

JNIEXPORT void JNICALL Java_com_example_tenpercent_ndkopengles2triangle_NativeWrapper_nativeInit
  (JNIEnv *, jclass)
{
  triangle.init ();
}

JNIEXPORT void JNICALL Java_com_example_tenpercent_ndkopengles2triangle_NativeWrapper_nativeResize
  (JNIEnv *, jclass, jint width, jint height)
{
    triangle.resizeView (width, height);
}

JNIEXPORT void JNICALL Java_com_example_tenpercent_ndkopengles2triangle_NativeWrapper_nativeDraw
  (JNIEnv *, jclass)
{
    triangle.draw ();
}

