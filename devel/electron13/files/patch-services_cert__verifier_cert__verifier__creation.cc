--- services/cert_verifier/cert_verifier_creation.cc.orig	2021-07-15 19:13:43 UTC
+++ services/cert_verifier/cert_verifier_creation.cc
@@ -71,7 +71,7 @@ scoped_refptr<net::CertVerifyProc> CreateCertVerifyPro
 
 bool IsUsingCertNetFetcher() {
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_CHROMEOS) || \
-    defined(OS_LINUX) ||                                                  \
+    defined(OS_LINUX) || defined(OS_BSD) ||                               \
     BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED) ||                \
     BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
   return true;
