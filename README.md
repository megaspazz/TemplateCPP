# TemplateCPP
C++ Template for Competitive Programming

temporary: using ms vs c++ compiler
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall" && cl %filepath% /EHsc /Fo.\obj\ /link /out:bin\%filename%.exe && ECHO Compilation successful. && bin\%filename%.exe < io/in.txt > io/out.txt && ECHO Execution successful.