#/bin/bash
USER='sigmaeduindia'
PASSWORD='mohitsirsigma1'

pftp -nv files.000webhost.com<<HULULU
quote USER $USER
quote PASS $PASSWORD
cd public_html/report
put rpt.html
quit
HULULU
