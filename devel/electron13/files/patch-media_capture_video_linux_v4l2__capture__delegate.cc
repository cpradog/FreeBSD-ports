--- media/capture/video/linux/v4l2_capture_delegate.cc.orig	2021-07-15 19:13:41 UTC
+++ media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,8 +4,10 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if !defined(OS_BSD)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
@@ -25,10 +27,10 @@
 
 using media::mojom::MeteringMode;
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
+// #if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
-#endif
+// #endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
