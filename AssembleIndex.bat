@ECHO OFF
:: Prepare the Command Processor

set SolutionDirectory=%~dp0
START  /b /wait "HTLATEX" /d  "%SolutionDirectory%" htlatex CrackingTheCodingInterview.tex ../StudySeriesStyles/blog.cfg
echo.
echo.
echo  			HTLATEX done...
echo.
echo.
START  /b /wait "Bootstrapify" /d  "%SolutionDirectory%" Bootstrapify.exe CrackingTheCodingInterview.html file.html
echo.
echo  			Bootstrapify done...
echo.
echo.
START /b /wait "BeautifulSoup"  C:\Anaconda\python.exe ../StudySeriesStyles/BeautifyHtml/BeautifyHtml.py -i "E:/Claudio/git/sites/CrackingTheCodingInterview/file.html" -o "E:/Claudio/git/sites/CrackingTheCodingInterview/index.html"
echo.
echo.
echo  			BeautifulSoup done...
echo.
echo.
del file.html
START  /b /wait "XELATEX" /d  "%SolutionDirectory%" xelatex -enable-write18 -synctex=-1 -max-print-line=120 "CrackingTheCodingInterview.tex" 
echo.
echo.
echo  			XELATEX done...
echo.
echo.
goto :eof