cat /etc/passwd | sed '/#/d' | awk '(NR%2)==0' | sed 's/\:.*//' | rev | sort -r | awk -v f1=$FT_LINE1 -v f2=$FT_LINE2 '(NR>=f1) && (NR<=f2)' | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $//' | sed 's/$/./' | tr -d '\n'
