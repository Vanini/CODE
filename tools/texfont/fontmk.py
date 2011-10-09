import os
import sys
import glob

filename = sys.argv[1] 
fontname = sys.argv[2]

os.chdir("./font")
for i in glob.glob("*"):
	os.system("cp %s ../%s"%(i,i))
os.chdir("./..")

os.system("fontforge -script subfonts.pe %s %s Unicode.sfd"%(filename, fontname))

open("makemap","w").write('''
for i in *.tfm
do
cat >> %s.map << EOF
${i%%.tfm} ${i%%.tfm} < ${i%%.tfm}.pfb
EOF
done
'''%(fontname))

os.system("sudo chmod +x makemap")
os.system("./makemap")

open("c70%s.fd"%(fontname),"w").write('''
\ProvidesFile{c70%s.fd}
\DeclareFontFamily{C70}{%s}{\hyphenchar \\font\m@ne}
\DeclareFontShape{C70}{%s}{m}{n}{<-> CJK * %s}{}
\DeclareFontShape{C70}{%s}{bx}{n}{<-> CJKb * %s}{\CJKbold}
\endinput
'''%(fontname,fontname,fontname,fontname,fontname,fontname))

os.system("mkdir -p ~/.texmf-var/fonts/map/dvips/CJK")
os.system("mkdir -p ~/.texmf-var/fonts/tfm/CJK/%s"%(fontname))
os.system("mkdir -p ~/.texmf-var/fonts/type1/CJK/%s"%(fontname))
os.system("mkdir -p ~/.texmf-var/tex/latex/CJK/UTF8")

os.system("cp ./%s.map ~/.texmf-var/fonts/map/dvips/CJK"%(fontname))
os.system("cp ./*.tfm ~/.texmf-var/fonts/tfm/CJK/%s"%(fontname))
os.system("cp ./*.pfb ~/.texmf-var/fonts/type1/CJK/%s"%(fontname))
os.system("cp ./c70%s.fd ~/.texmf-var/tex/latex/CJK/UTF8"%(fontname))

os.system("sudo texhash")
os.system("updmap --enable Map %s.map"%(fontname))

for i in glob.glob("*"):
	if i != "font" and i != filename and i != sys.argv[0]:
		os.system("rm -r %s"%(i))

