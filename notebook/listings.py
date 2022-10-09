import sys
import os

def lines_strip(filename):
    """get list of lines in file"""
    return [l.rstrip() for l in open(filename, 'r').readlines()]

def code(lines, skip_title=True):
    if skip_title:
        lines = lines[1:]
    for l in lines:
        print(l)

def section(name):
    print("\n" + "%"*20 + "\n% " + name + "\n" + "%"*20 + "\n")
    print("\\section{" + name + "}\n")

def listing(filename):
    lines = lines_strip(filename)
    name = lines[0][3:] # remove '// '
    print("\\subsection{" + name + "}")
    print("\\begin{lstlisting}")
    code(lines)
    print("\\end{lstlisting}\n")

if __name__=="__main__":
    base_path = os.path.join(os.getcwd(), "../code")
    code_dirs = os.listdir(base_path)
    code_dirs.sort()
    # extra comes last
    code_dirs.pop(code_dirs.index("extra"))
    code_dirs.append("extra")
    for d in code_dirs:
        section(d[0].upper() + d[1:])
        d_path = os.path.join(base_path, d)
        for f in os.listdir(d_path):
            listing(os.path.join(d_path, f))
    print("\\pagebreak")
    print("\\end{document}")
