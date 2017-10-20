set term gif animate
set yrange [0:1]
set output 'output/O.gif'
do for [i=1:50]{
plot 'output/kni_P.txt' u i w l lc 18 t 'kni','output/hb_P.txt' u i w l lc 7 t 'hb','output/kr_P.txt' u i w l lc 14 t 'kr','output/gt_P.txt' u i w l lc 21 t 'gt' 
set title sprintf("%d",i)
}

set term png
set output 'output/fi.png'
set yrange [0:1]
plot 'output/final_P.txt' u 1 w l lc 18 t 'kni','' u 2 w l lc 7 t 'hb','' u 3 w l lc 14 t 'kr','' u 4 w l lc 21 t 'gt'

