#include "Functions.h"
#define DELAY_NOTI 1000


bool CheckLetter(char s)
{
	if((s>= 65 && s<= 90) || (s>= 97 && s<= 122 ) || (s==32))
	{
		return 1;
	}
	return 0;	 
}

bool CheckNum(char s)
{
		if(s >= 48 && s <= 57)
		{
			return 1;
		}
	return 0;	 
}

int ChangeCharToNum (char s[],int n)
{
	n = 0;
	for(int i =0; i<strlen(s);i++)
	{
		n = n*10 + s[i];
	}
	return n;
}

void AddChuoi(char c, char s[])
{
	strncat(s, &c,1);
}

void get_chuoi(char *des, char *s )
{
	int index = 0;
	for(int i=0; i<strlen(s); i++)
	{
		if(s[i] != ' ')
		{
			des[index] = tolower(s[i]);
			index++;
		}
	}
	des[index] ='\0';
}

void delBlank(char *s)
{
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i]==' ')
		{
			s[i] = s[i+1];
			for(int j = i+1;j<strlen(s)-1;j++)
			{
				s[j] = s[j+1];
			}
			s[strlen(s)-1] = '\0';
		}
	}
}

int KiemtraNhapLieu(char c, char s[])
{
	if(strlen(s) == 0 && c == ' ') // block space
		return 0;
	else	
		if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ') // block double space 
			return 0;	
	else	
		if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || (strlen(s) == 0 && c != ' '))// upper Letter
			return -1;
	return 1;	 
}

bool KhoaNhapLieu(char s[], int n)
{
	if(strlen(s)<n)
		return 1;
	return 0;	
}

void Nhap(int x, int y,int check, char c, char s[], int n)
{
	c = tolower(c);
	if(c == 8 && strlen(s) != 0)
	{
		s[strlen(s)-1] = '\0';
	}	
	if(check == 1)
	{
		if(CheckLetter(c) && KhoaNhapLieu(s,n))
		{
			if(KiemtraNhapLieu(c,s) == 1)
			{
				AddChuoi(c,s);
//				outtextxy(x,y,s);
			}
			else
				if(KiemtraNhapLieu(c,s)==-1)
				{
					c = toupper(c);
					AddChuoi(c,s);
				}		
		}
		
	}
	else
	if(check==0)
	{
		if(CheckNum(c) && KhoaNhapLieu(s,n))
		{
			if(KiemtraNhapLieu(c,s) == 1 || KiemtraNhapLieu(c,s) == -1)
			{
				AddChuoi(c,s);
			}
		}
	}
	else
	if(check == -1)
	{
		if((CheckNum(c) || CheckLetter(c)) && KhoaNhapLieu(s,n) && c != ' ')
		{
			
			if(KiemtraNhapLieu(c,s) == 1|| KiemtraNhapLieu(c,s) == -1)
			{
				c = toupper(c);
				AddChuoi(c,s);
			}
		}
	}
	setcolor(WHITE);
	setbkcolor(NEN_TEXT);
	outtextxy(x,y,s);
}

void Qsort(NamesInfo info[], int left, int right)
{
	NamesInfo mid = info[(left + right) / 2];
	int i = left, j = right;
	do
	{
		while(strcmp(info[i].name, mid.name) < 0)
			i++;
		while(strcmp(info[i].name, mid.name) > 0)
			j++;
		if(i <= j)
		{
			if(i < j)
			{
				NamesInfo tmp;
				tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
			i++; j--;
		}
	} while(i<=j);
	if(left < j)
		Qsort(info,left,j);
	if(right > i)
		Qsort(info,i,right);
}

char* toChars(int num)
{
	char* a = new char[100];
	if (num == 0)
	{
		a[1] = '\0';
		a[0] = '0';
	}
	else
	{
		int l = floor(log10(num)+1);
		a[l--] = '\0';
		while(num>0)
		{
			a[l--] = num%10+48; //to char
			num/=10;
		}
	}
	return a;
}

int canLeGiua(char *S, int dis)
{
	return (dis-textwidth(S))/2;
}


//Ham do hoa

void InThongTin(int x, int y, const char *s)
{
	setcolor(WHITE);
	outtextxy(x, y, s);
}

void ThongBao(int x, int y, char noti[50], int mauChu, int mauNen)
{	
	setbkcolor(mauNen);
	setcolor(mauChu);
	outtextxy(x, y, noti);
	Sleep(DELAY_NOTI);
	setfillstyle(SOLID_FILL, mauNen);
	bar(x, y, x + textwidth(noti), y + textheight(noti));
}

void showPage(int x, int y, int page, int limit)
{
	//  Page: page / limit
	setcolor(MAU_TEXT_KHUNG);
	outtextxy(x, y, "Page: ");
	x += textwidth("Page: ");
	
	outtextxy(x, y, toChars(page));
	x += textwidth(toChars(page));
	
	outtextxy(x, y, " / ");
	x += textwidth(" / ");	
	
	outtextxy(x, y, toChars(limit));
}

