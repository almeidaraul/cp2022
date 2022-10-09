#!/bin/bash
cp header.tex pdf/notebook.tex
cp notes.tex pdf/notes.tex
python3 listings.py >> pdf/notebook.tex
cd pdf
pdflatex notebook.tex
pdflatex notes.tex
mv *.pdf ../../
