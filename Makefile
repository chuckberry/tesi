
SOURCE = thesis

all: pdf report

dvi: $(SOURCE).dvi $(SOURCE).bbl
$(SOURCE).dvi: $(SOURCE).tex $(SOURCE).bbl
	latex $<
	latex $<
	
ps: $(SOURCE).ps
$(SOURCE).ps: $(SOURCE).dvi
	dvips -Ppdf -G0 -ta4 -o $@ $<

pdf: $(SOURCE).pdf
$(SOURCE).pdf: $(SOURCE).ps
	ps2pdf -dSubsetFonts=true -dMaxSubsetPct=100 -dEmbedAllFonts=true -dUseFlateCompression=true -dCompatibilityLevel=1.4 -dPDFSETTINGS=/prepress $< $@

bib: $(SOURCE).bbl
$(SOURCE).bbl : $(SOURCE).bib
	latex $(SOURCE).tex
	bibtex $(SOURCE)1
	#bibtex $(SOURCE)2
	#latex $(SOURCE).tex

report: $(SOURCE).pdf
	pdffonts $< > fonts.log
	cat fonts.log

clean:
	rm -rf *.bbl *.blg *.out *.aux *.dvi *.log *.ps *.backup *~ *.bak *.toc *.idx *.DS_Store ./*/*.aux

