## Bashrc
xmodmap -e 'clear lock' -e 'keycode 66=Escape' # caps -> esc
alias e=vim

BASE_CP="/home/raul/cp2022"

alias c='g++ -Wall -Wconversion -Wfatal-errors -g -O2 -std=gnu++17 -fsanitize=undefined,address'
alias c14='g++ -Wall -Wconversion -Wfatal-errors -g -O2 -std=gnu++14 -fsanitize=undefined,address'
alias p3='pypy3 -m py_compile'

tp () { 
	[ -f "$1.cpp" ] && echo "$1.cpp already exists";
	[ ! -f "$1.cpp" ] && tail -n +2 $BASE_CP/code/extra/template.cpp > $1.cpp && vim $1.cpp;
}

clip () {
	if [ -f "$1" ];
	then
		cat $1 | clip.exe;
	else
		echo "$1 not found"
	fi
}
