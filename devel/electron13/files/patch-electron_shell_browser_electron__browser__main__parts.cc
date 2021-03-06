--- electron/shell/browser/electron_browser_main_parts.cc.orig	2021-10-27 21:25:28 UTC
+++ electron/shell/browser/electron_browser_main_parts.cc
@@ -59,7 +59,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "base/threading/thread_task_runner_handle.h"
@@ -157,7 +157,7 @@ std::u16string MediaStringProvider(media::MessageId id
   }
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void OverrideLinuxAppDataPath() {
   base::FilePath path;
   if (base::PathService::Get(DIR_APP_DATA, &path))
@@ -185,7 +185,7 @@ void UpdateDarkThemeSetting() {
 
 }  // namespace
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class DarkThemeObserver : public ui::NativeThemeObserver {
  public:
   DarkThemeObserver() = default;
@@ -234,7 +234,7 @@ int ElectronBrowserMainParts::GetExitCode() const {
 
 int ElectronBrowserMainParts::PreEarlyInitialization() {
   field_trial_list_ = std::make_unique<base::FieldTrialList>(nullptr);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   OverrideLinuxAppDataPath();
 #endif
 
@@ -291,7 +291,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
 #if defined(USE_AURA)
   display::Screen* screen = views::CreateDesktopScreen();
   display::Screen::SetScreenInstance(screen);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   views::LinuxUI::instance()->UpdateDeviceScaleFactor();
 #endif
 #endif
@@ -308,7 +308,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -331,7 +331,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -386,7 +386,7 @@ void ElectronBrowserMainParts::ToolkitInitialized() {
     ui::GtkUiDelegate::SetInstance(gtk_ui_delegate_.get());
   }
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   views::LinuxUI* linux_ui = BuildGtkUi(ui::GtkUiDelegate::instance());
   views::LinuxUI::SetInstance(linux_ui);
   linux_ui->Initialize();
