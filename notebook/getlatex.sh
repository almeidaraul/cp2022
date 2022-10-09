#!/bin/bash
cp header.tex pdf/notebook.tex
python3 listings.py >> pdf/notebook.tex
cd pdf
pdflatex notebook.tex
