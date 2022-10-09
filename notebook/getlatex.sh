#!/bin/bash
cp header.tex pdf/notebook.tex
cp notes.tex pdf/notes.tex
cp tracker.tex pdf/tracker.tex
python3 listings.py >> pdf/notebook.tex
cd pdf
pdflatex notebook.tex
pdflatex notes.tex
pdflatex tracker.tex
mv *.pdf ../../
