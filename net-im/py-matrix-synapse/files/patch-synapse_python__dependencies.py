--- synapse/python_dependencies.py.orig	2022-02-22 11:32:11 UTC
+++ synapse/python_dependencies.py
@@ -86,7 +87,7 @@ REQUIREMENTS = [
     "typing-extensions>=3.7.4",
     # We enforce that we have a `cryptography` version that bundles an `openssl`
     # with the latest security patches.
-    "cryptography>=3.4.7",
+    "cryptography",
     "ijson>=3.1",
     "matrix-common~=1.1.0",
 ]
