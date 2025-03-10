data fig1_1;
do t=1 to 100;
z=5000+20*rannor(1234);
output;
end;run;

data fig1_1;
set fig1_1;
date=intnx('month', '1jan80'd,_n_-1);
format date mmddyy.;run;

proc sgplot;
series x=date y=z;
refline 5000/axis=y;run;