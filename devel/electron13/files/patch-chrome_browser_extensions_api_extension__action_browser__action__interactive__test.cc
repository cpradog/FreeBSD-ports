--- chrome/browser/extensions/api/extension_action/browser_action_interactive_test.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/extensions/api/extension_action/browser_action_interactive_test.cc
@@ -282,7 +282,7 @@ IN_PROC_BROWSER_TEST_F(BrowserActionInteractiveTest, T
   frame_observer.Wait();
   // Non-Aura Linux uses a singleton for the popup, so it looks like all windows
   // have popups if there is any popup open.
-#if !((defined(OS_LINUX) || defined(OS_CHROMEOS)) && !defined(USE_AURA))
+#if !((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && !defined(USE_AURA))
   // Starting window does not have a popup.
   EXPECT_FALSE(ExtensionActionTestHelper::Create(browser())->HasPopup());
 #endif
