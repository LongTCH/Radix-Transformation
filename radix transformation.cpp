#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void swap(int *a, int *b){
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

void tinh2mun(int *a, int n, int *l){ //Big int pow (2,n)
	int x,r,t;
	int len=1,i=0;
	a[0]=1;
	if (n>=0)
	{
		while (i<n)
    	{
    		x=0;r=0;t=0;
    		while (x<len)
    		{
    			t=a[x]*2+r;
    			a[x]=t%10;
    			r=t/10;
    			x++;
    		}
    		while (r>0)
    		{
    			a[len]=r%10;
    			r/=10;
    			len++;
    		}
    		i++;
    	}
    	for (i=0;i<len/2;i++) swap (&a[i],&a[len-i-1]);
	}
	else
	{
		i=1;
		len=2;
		a[0]=0;
		a[1]=5;
		while (i<(-1)*n)
		{
			x=1;t=0;r=0;
			while (x<len)
			{
				t=a[x]+10*r;
				a[x]=t/2;
    			r=t-2*a[x];
    		
    			x++;
			}
			while (r>0)
			{
				r=r*10;
				a[len]=r/2;
				len++;
				break;
			}
			i++;
		}
	}
	*l=len;
}

void congnguyen(int *a, int *b, int *laa, int *lbb){ //laa>=lbb Add 2 int
	int la=*laa;
	int lb=*lbb;
	int temp=0,i,j,r=0,dem=0;
	
	for (i=0;i<la;i++) a[la-i]=a[la-i-1];
	a[0]=0;la++;
	for (i=lb-1;i>=0;i--) b[i+la-lb]=b[i];
	for (i=0;i<la-lb;i++) b[i]=0;
	for (i=la-1;i>=0;i--)
	{
		temp=a[i]+b[i]+r;
		a[i]=temp%10;
		r=temp/10;
	}
	while (a[dem]==0) dem++;
	for (i=0;i<la;i++) a[i]=a[i+dem];
	la=la-dem;
	*laa=la;
}

void congtp(int *a, int *b, int *la, int *lb){ //la>=lb Add 2 fraction
	int i,len,r=0;
	int temp=0,dem=0;
	len=*la;
	for (i=len-1;i>=0;i--)
	{
		temp=a[i]+b[i]+r;
		a[i]=temp%10;
		r=temp/10;
	}
}

void daobitcong1(int *a,int *l){ //Reverse bit string then add 1 at last
	int i,len,temp,check;
	len=*l;
	check=a[0];
	for (i=0;i<len;i++) {if (a[i]==1) a[i]--; else a[i]++;}//reverse bit string
    temp=1;
    for (i=len-1;i>=0;i--)
    {
    	a[i]+=temp;
    	temp=0;
		if (a[i]==2) 
	    {
		   	a[i]=0;
		   	temp=1;
    	} 
   	}
   	if (check==a[0]) 
    {
    	for (i=len-1;i>=0;i++) a[i+1]=a[i];
    	a[0]=0;
    	*l=len+1;
	}
}

void chuanhoadauvaos102(char *s, int *l){ // process input of tranform radix system from 10 to 2
	int len=*l;
	int i,dem=0;
	while (s[dem]=='0') dem++;
	for (i=0;i<len;i++) s[i]=s[i+dem];
	len=len-dem;
	if ((s[0]=='0')&&(s[1]=='.')) 
	{
		for (i=0;i<len;i++) s[len-i]=s[len-i-1];
		len++;
	}
	if (s[0]=='-')
	{
		dem=0;
		while (s[dem+1]=='0') dem++;
		for (i=0;i<len;i++) s[i+1]=s[i+dem+1];
    	len=len-dem;
    	if ((s[0]=='0')&&(s[1]=='.') )
    	{
	    	for (i=0;i<len;i++) s[len-i]=s[len-i-1];
    		len++;
    	}
	}
	*l=len;
}

void chuanhoadauvaos210(char *s, int *l){ //process input of tranform radix system from 2 to 10
	int i,len;
	len=*l;
	for (i=0;i<len;i++) s[len-i]=s[len-i-1];
	s[0]='0';
	*l=len+1;
}

int transgr328(int q1, int q2, int q3){ //transfrom 3 bit of base 2 into 1 bit of base 8
	if (q1==1) q1=4;
	if (q2==1) q2=2;
	return q1+q2+q3;
}

char transgr4216(int q1, int q2, int q3, int q4){//transfrom 4 bit of base 2 into 1 bit of base 16
	int sum=0;
	if (q1==1) q1=8;
	if (q2==1) q2=4;
	if (q3==1) q3=2;
	sum=q1+q2+q3+q4;
	if (sum < 10) return sum+48;
	return sum+55;
	
}

void transgr4162(char s, char he2[], int i){//transfrom 1 bit of base 16 into 4 bit of base 2
	char temp[16][5]={"0000","0001","0010","0011",
	                  "0100","0101","0110","0111",
					  "1000","1001","1010","1011",
					  "1100","1101","1110","1111"};
	for (int j=0; j<4; j++) he2[i+j]=temp[s-48][j];
}

void transgr382(char s, char he2[], int i){//transfrom 1 bit of base 8 into 3 bit of base 2
	char temp[8][4]={"000","001","010","011","100","101","110","111"};
	for (int j=0; j<3; j++) he2[i+j]=temp[s-48][j];
}

void s102(char *ch, int *l){ //two's complement
	int i,len,af,signad;
	int be=0,demhe2=0,demk=0,sign=0;
	int temp,tpbe,index;
	int k[1000]={0},p[1000]={0},he2[1000]={0};
	len=*l;
	
	chuanhoadauvaos102(ch, &len);
	if (ch[0]=='-') //kiem tra so - hay +
	{
		sign=1;
		for (i=0;i<len-1;i++) ch[i]=ch[i+1];//xoa dau de dua ve chuoi chi chua so
		len--;		
	}
	
	for (i=0;i<len;i++)//tim vi tri dau .
	{
		be++;
		if (ch[i]=='.') break;
	}
	demk=be;
	if (be<len) demk--;
//doi phan nguyen sang he 2
	for (i=0;i<demk;i++)
	{
		k[i]=ch[i]-48;
	}
	do //divide by 2 using array
	{
		index=tpbe=temp=0;
		if ((k[0]==1)&&(demk>1))
		{
			temp=k[0]*10+k[1];
			p[0]=temp/2;
			temp=10*(temp-p[0]*2);
			index+=2;
			tpbe++;
		}
    	while (index<demk)
    	{
    		temp=temp+k[index];
    		p[tpbe]=temp/2;
    		temp=10*(temp-p[tpbe]*2);
    		tpbe++;index++;
    		
    	}
    	he2[demhe2]=temp/10;
    	demk=tpbe;
    	demhe2++;
    	for(i=0;i<demk;i++) k[i]=p[i];
	} while (k[0]>0);

	
	for (i=0;i<(demhe2+1)/2;i++) swap(&he2[i],&he2[demhe2-i]);//dua chuoi ve dung thu tu

	signad=++demhe2;//luu vi tri dau . demhe2 la so ptu cua phan nguyen
//neu la thap phan
	if (be<len)
    {
    	int stop=0;
		for (i=be,af=1;i<len;i++,af++) k[af]=ch[i]-48;
		af--;

		while (1)
    	{
    		temp=0;
        	for (i=af;i>=0;i--)
        	{
    	    	temp=k[i]*2+temp;
		    	k[i]=temp%10;
		    	temp/=10;
	    	}

	    	
	    	he2[demhe2]=k[0];
			demhe2++;
		    k[0]=0;
		 
	    	while ((k[af]==0)&&(af>0)) af--;
	    	stop++;
	    	if ((af==0)||(stop==100)) break;
		}
		
	}
//demhe2 la do dai he2
//neu n<0	
    if (sign==1) daobitcong1(he2,&demhe2);

	for (i=0;i<signad;i++) ch[i]=he2[i]+48;
	if (be<len) 
	{
	    ch[signad]='.';	
	    for (i=signad;i<demhe2;i++) ch[i+1]=he2[i]+48;
	    *l=demhe2+1;
	} else
	{
		for (i=signad;i<demhe2;i++) ch[i]=he2[i]+48;
		*l=demhe2;
	}
}

void s210(char *s, int *l){
	
	int a[1000]={0},sum1[1000]={0},sum3[1000]={0};
	int i,af,sign=0,temp,len,lmax,lalt,ltp,ltpmax,ltpalt;
	int be=0,dem=0;
	int *sum2;
	int *sum4;
	len=*l;
	
	if (s[1]=='.') //x.xxx -> xx.xxx because funtion transform base from 2 to 10 with integral part is two's  complement
	{
		for (i=0;i<len;i++) s[len-i]=s[len-i-1];
		len++;
	}
	for (i=0;i<len;i++)// s[be-1]=='.'
	{
		be++;
		if (s[i]=='.') break;
	}
	if (be<len)
	{
		for (i=be;i<len;i++) s[i-1]=s[i];//remove '.' out of string
		    len--;
		for (i=0;i<len;i++) a[i]=s[i]-48;
		if (a[0]==1)
		{
			sign=1;
			be=len-be;
			daobitcong1(a,&len);
			be=len-be; //s[be-1]=='.'
		}
		// 2^x1 + 2^x2 + ... integral part
		tinh2mun(sum1,be-3,&lmax);
		for (i=0;i<lmax;i++) sum1[i]*=a[1];

		for (i=2;i<be-1;i++) 
		{
			if (a[i]==1)
			{
				sum2 = (int*) calloc(1000, sizeof(int));
				tinh2mun(sum2,be-i-2,&lalt);
			    congnguyen(sum1,sum2,&lmax,&lalt);
			    free(sum2);
			}
		}
		ltp=len+1-be;//length of fractional part
		// 2^x1 + 2^x2 + ... fractional part
		tinh2mun(sum3,(-1)*ltp,&ltpmax);
		for (i=0;i<ltpmax;i++) sum3[i]*=a[len-1];
		for (i=len-2;i>=be-1;i--)
		{
			ltp--;
			if (a[i]==1)
			{
				sum4 = (int*) calloc(1000, sizeof(int));
				tinh2mun(sum4,(-1)*ltp,&ltpalt);
				congtp(sum3,sum4,&ltpmax,&ltpalt);
				free(sum4);
			}
		}
		while ((sum3[ltpmax-dem-1]==0)&&(dem<ltpmax)) dem++; //count number of consecutive 0s from last of fraction
	    ltpmax=ltpmax-dem;

		if (sign==1)//match 2 string for result
		{
			s[0]='-';
			for (i=0;i<lmax;i++) s[i+1]=sum1[i]+48;
			if (ltpmax>0) s[lmax+1]='.';
			for (i=1;i<ltpmax;i++) s[i+lmax+1]=sum3[i]+48;
			*l=lmax+ltpmax+1;
		}else
		{
			for (i=0;i<lmax;i++) s[i]=sum1[i]+48;
			if (ltpmax>0) s[lmax]='.';
			for (i=1;i<ltpmax;i++) s[i+lmax]=sum3[i]+48;
			*l=lmax+ltpmax;
		}
	}
	else
	{
		for (i=0;i<len;i++) a[i]=s[i]-48;
		if (a[0]==1)
		{
			sign=1;
			daobitcong1(a,&len);
		}
		tinh2mun(sum1,len-2,&lmax);
		for (i=0;i<lmax;i++) sum1[i]*=a[1];
		for (i=2;i<len;i++) 
		{
			if (a[i]==1)
			{
				sum2 = (int*) calloc(1000, sizeof(int));
				tinh2mun(sum2,len-i-1,&lalt);
			    congnguyen(sum1,sum2,&lmax,&lalt);
			    free(sum2);
			}
		}

		if (sign==1)//match string for result
		{
			s[0]='-';
			for (i=0;i<lmax;i++) s[i+1]=sum1[i]+48;
			*l=lmax+1;
		}else
		{
			for (i=0;i<lmax;i++) s[i]=sum1[i]+48;
			*l=lmax;
		}
	}

}

void s28(char *s, int *l){
	int i,index,len,q1,q2,q3,lenhe8,be,signad;
	int he8[1000]={0};
	len=*l;
	lenhe8=0; be=0; signad=0;
	for (i=0;i<len;i++) //s[be-1]=='.'
	{
		be++;
		if (s[i]=='.') break;
	}
	if (be<len) index=be-2; else index=len-1;

	while (index >= 0)//transform integral part
	{
		q1=q2=q3=0;
		if (s[index]=='1') q3=1; 
		if ((index-1>=0)&&(s[index-1]=='1')) q2=1; 
		if ((index-2>=0)&&(s[index-2]=='1')) q1=1;
		he8[lenhe8]=transgr328(q1,q2,q3);
		lenhe8++;signad++;
		index-=3;
	}
	for (i=0;i<lenhe8/2;i++) swap(&he8[i],&he8[lenhe8-i-1]); 
	index=be;
	
	while (len-index>0)//transform fractional part
	{
		q1=q2=q3=0;
		if (s[index]=='1') q1=1; 
		if ((len-index-1>=0)&&(s[index+1]=='1')) q2=1; 
		if ((len-index-2>=0)&&(s[index+2]=='1')) q3=1; 
		he8[lenhe8]=transgr328(q1,q2,q3);
		lenhe8++;
		index+=3;
	}
	if (be<len)//match string for result
	{
		for (i=0;i<signad;i++) s[i]=he8[i]+48;
		s[signad]='.';
		for (i=signad;i<lenhe8;i++) s[i+1]=he8[i]+48;
		*l=lenhe8+1;
	}else
	{
		for (i=0;i<lenhe8;i++) s[i]=he8[i]+48;
		*l=lenhe8;
	}
	
}

void s216(char *s, int *l){
	int i,index,len,q1,q2,q3,q4,lenhe16,be,signad;
	char he16[256];
	len=*l;
	lenhe16=0; be=0; signad=0;
	for (i=0;i<len;i++) //s[be-1]=='.'
	{
		be++;
		if (s[i]=='.') break;
	}
	if (be<len) index=be-2; else index=len-1;

	while (index >= 0)//transform integral part
	{
		q1=q2=q3=q4=0;
		if (s[index]=='1') q4=1; 
		if ((index-1>=0)&&(s[index-1]=='1')) q3=1; 
		if ((index-2>=0)&&(s[index-2]=='1')) q2=1;
		if ((index-3>=0)&&(s[index-3]=='1')) q1=1;
		he16[lenhe16]=transgr4216(q1,q2,q3,q4);
		lenhe16++;signad++;
		index-=4;
	}
	
	for (i=0;i<lenhe16/2;i++) 
	{
		he16[i]=he16[i]+he16[lenhe16-i-1];
		he16[lenhe16-i-1]=he16[i]-he16[lenhe16-i-1];
		he16[i]=he16[i]-he16[lenhe16-i-1];
	}
	index=be;
	
	while (len-index>0)//transform fractional part
	{
		q1=q2=q3=q4=0;
		if (s[index]=='1') q1=1;
		if ((len-index-1>=0)&&(s[index+1]=='1')) q2=1; 
		if ((len-index-2>=0)&&(s[index+2]=='1')) q3=1; 
		if ((len-index-3>=0)&&(s[index+3]=='1')) q4=1;
		he16[lenhe16]=transgr4216(q1,q2,q3,q4);
		lenhe16++;
		index+=4;
	}
	if (be<len)//match string for result
	{
		for (i=0;i<signad;i++) s[i]=he16[i];
		s[signad]='.';
		for (i=signad;i<lenhe16;i++) s[i+1]=he16[i];
		*l=lenhe16+1;
	}else
	{
		for (i=0;i<lenhe16;i++) s[i]=he16[i];
		*l=lenhe16;
	}
	
}

void s82(char *s, int *l){
	int i,len,lenhe2;
	char he2[256];
	len=*l;
	lenhe2=0; 
	for (i=0;i<len;i++) 
	{
		if (s[i]=='.') 
		{
			he2[lenhe2]='.';
			lenhe2++;
			continue;
		} 
		transgr382(s[i],he2,lenhe2);
		lenhe2+=3;
	}
	for (i=0;i<lenhe2;i++) s[i]=he2[i];
	*l=lenhe2; 
	
}

void s162(char *s, int *l){
	int i,len,lenhe2;
	char he2[256];
	len=*l;
	lenhe2=0; 
	for (i=0;i<len;i++) 
	{
		if (s[i]=='.') 
		{
			he2[lenhe2]='.';
			lenhe2++;
			continue;
		} 
		transgr4162(s[i], he2, lenhe2);
		lenhe2+=4;
	}
	for (i=0;i<lenhe2;i++) s[i]=he2[i];
	*l=lenhe2; 
	
}

void s108(char *s, int *l){
	s102(s,l);
	s28(s,l);
}

void s1016(char *s, int *l){
	s102(s,l);
	s216(s,l);
}

void s1610(char *s, int *l){
	s162(s,l);
	chuanhoadauvaos210(s,l);
	s210(s,l);
}

void s810(char *s, int *l){
	s82(s,l);
	chuanhoadauvaos210(s,l);
	s210(s,l);
}

int main(){
	int l,i;
	char s[256];
	printf("Nhap chuoi la:");gets(s);
	l=strlen(s);

	s210(s,&l);
	printf("\n");
	for (i=0;i<l;i++) printf("%c",s[i]);
	s102(s,&l);
	printf("\n");
	for (i=0;i<l;i++) printf("%c",s[i]);

	return 0;
}
