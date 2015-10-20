#include "Sparce.h"
#include <iomanip> // setw
#include <stdexcept>
using namespace std;



Sparce::Sparce(int ** a , int r, int c)
{
	int term = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if(a[i][j] != 0)
				term++;

	cells = new Cell[term];
	setRow(r);
	setCol(c);
	setValue(term);

	int cellCount = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if(a[i][j] != 0)
			{
				cells[cellCount++].setCell(i,j,a[i][j]);
			}


}

Sparce::Sparce( Sparce & a )
{
	cells = new Cell[a.value];
	setRow(a.getRow());
	setCol(a.getCol());
	setValue(a.value);


	for (int i = 0; i < value; i++)
	{
		cells[i].setCell(a.getRowX(i),a.getRowY(i),a.getRowValue(i));
	}

}

Sparce::Sparce (int r , int c , int term)
{
	cells = new Cell[term];
	setRow(r);
	setCol(c);
	setValue(term);
}

Sparce::~Sparce(void)
{
	//delete[] cells;
}


int Sparce::getRow()
{
	return row;
}


int Sparce::getCol()
{
	return col;
}

int Sparce::getValue()
{
	return value;
}



void Sparce::setRow(int r)
{
	row = r;
}

void Sparce::setCol(int c)
{
	col = c;
}

void Sparce::setValue(int v)
{
	value = v;
}


int Sparce::getRowX(int i)
{
	return cells[i].getRow();
}
int Sparce::getRowY(int i)
{
	return cells[i].getCol();
}
int Sparce::getRowValue(int i)
{
	return cells[i].getValue();
}

Sparce Sparce::operator+ (Sparce sp2)
{
	if(getRow() != sp2.getRow() || getCol() != sp2.getCol())
		throw std::exception("For adding two array most have same rows and coloumns");


	int satr1 = 0 , satr2 = 0 , satr3 = 0;

	while (satr1 < getRow() && satr2<sp2.getRow())
	{
		if(getRowX(satr1) < sp2.getRowX(satr2)) // agar satr avali kamtar bashe unu mizarim too matris javab
		{
			satr1++;
			satr3++;
		}
		else if(getRowX(satr1) > sp2.getRowX(satr2)) //agar satr dovomi kamtar bashe unu mizarim too matris javab
		{
			satr2++;
			satr3++;
		}
		else if(getRowX(satr1) == sp2.getRowX(satr2)) // agar satr ha barabar bashan soton haro check mikonim
		{
			if (getRowY(satr1) < sp2.getRowY(satr2))
			{
				satr1++;
				satr3++;
			}
			else if(getRowY(satr1) > sp2.getRowY(satr2)) 
			{
				satr2++;
				satr3++;
			}
			else if(getRowX(satr1) == sp2.getRowX(satr2)) // agar ha satr va ham soton barabar bashe ba ham jam mishan
			{
				satr1++;
				satr2++;
				satr3++;
			}
		}//barabar boodan satr ha
	}//while

	while(satr1<getValue())
	{
		satr1++;
		satr3++;
	}

	while(satr2<sp2.getValue())
	{
		satr2++;
		satr3++;
	}

	satr3--;
	Sparce res(getRow(),getCol(),satr3);

	satr1 = 0;
	satr2 = 0;
	satr3 = 0;

	while (satr1 < getRow() && satr2<sp2.getRow())
	{
		if(getRowX(satr1) < sp2.getRowX(satr2)) // agar satr avali kamtar bashe unu mizarim too matris javab
		{
			res.cells[satr3].setCell(getRowX(satr1),getRowY(satr1),getRowValue(satr1));
			satr1++;
			satr3++;
		}
		else if(getRowX(satr1) > sp2.getRowX(satr2)) //agar satr dovomi kamtar bashe unu mizarim too matris javab
		{
			res.cells[satr3].setCell(sp2.getRowX(satr2),sp2.getRowY(satr2),sp2.getRowValue(satr2));
			satr2++;
			satr3++;
		}
		else if(getRowX(satr1) == sp2.getRowX(satr2)) // agar satr ha barabar bashan soton haro check mikonim
		{
			if (getRowY(satr1) < sp2.getRowY(satr2))
			{
				res.cells[satr3].setCell(getRowX(satr1),getRowY(satr1),getRowValue(satr1));
				satr1++;
				satr3++;
			}
			else if(getRowY(satr1) > sp2.getRowY(satr2)) 
			{
				res.cells[satr3].setCell(sp2.getRowX(satr2),sp2.getRowY(satr2),sp2.getRowValue(satr2));
				satr2++;
				satr3++;
			}
			else if(getRowX(satr1) == sp2.getRowX(satr2)) // agar ha satr va ham soton barabar bashe ba ham jam mishan
			{
				res.cells[satr3].setCell(sp2.getRowX(satr2),sp2.getRowY(satr2),getRowValue(satr1)+sp2.getRowValue(satr2));
				satr1++;
				satr2++;
				satr3++;
			}
		}//barabar boodan satr ha
	}//while

	while(satr1<getValue())
	{
		res.cells[satr3].setCell(getRowX(satr1),getRowY(satr1),getRowValue(satr1));
		satr1++;
		satr3++;
	}

	while(satr2<sp2.getValue())
	{
		res.cells[satr3].setCell(sp2.getRowX(satr2),sp2.getRowY(satr2),sp2.getRowValue(satr2));
		satr2++;
		satr3++;
	}

	return res;
}
Sparce Sparce::operator* (Sparce sp2)
{
	if( getRow() != sp2.getCol())
		throw std::exception("For multiply two array most have same rows and coloumns");
	int count = 0;
	count = 0;

	//aval shomaresh
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < sp2.getCol(); j++)
		{
			/*
			i va j khoone hayae matris javab hastan , dorost mesle zarb mamooli.
			alan aval check mikonim ke satr i om dar matris a hast ya na(ye row dare ye col ba n ke jash dar araye ast)
			agar satr i om bood bayad begardim bebinim sotoon j om dar matris b hast ya na
			agar unam bood , migardim bebinim aya col dar satr haye b hast ya na
			agar bood (khane m) sum += getRowValue(n)*sp2.getRowValue(m);
			*/
			int sum = 0;
			int n = findInRows(i);
			if (n != -1)//alan aval check mikonim ke satr i om dar matris a hast ya na(ye row dare ye col ba n ke jash dar araye ast)
			{
				while (getRowX(n) == i)
				{
					int m = sp2.findInCols(j,getRowY(n));
					if (m != -1)
					{
						sum += getRowValue(n)*sp2.getRowValue(m);
						//cout <<"\nC["<<i<<"]["<<j<<"] = a("<<n<<")*b("<<m<<")";
					}
					n++;
				}

				if (sum != 0)
				{
					count++;
				}

			}//if n != -1
		}
	}//for i

	Sparce res(getRow(),sp2.getCol(),count);

	//baad zarb
	count = 0;
	for (int i = 0; i < getRow(); i++)
	{
		for (int j = 0; j < sp2.getCol(); j++)
		{
			/*
			i va j khoone hayae matris javab hastan , dorost mesle zarb mamooli.
			alan aval check mikonim ke satr i om dar matris a hast ya na(ye row dare ye col ba n ke jash dar araye ast)
			agar satr i om bood bayad begardim bebinim sotoon j om dar matris b hast ya na
			agar unam bood , migardim bebinim aya col dar satr haye b hast ya na
			agar bood (khane m) sum += getRowValue(n)*sp2.getRowValue(m);
			*/
			int sum = 0;
			int n = findInRows(i);
			if (n != -1)//alan aval check mikonim ke satr i om dar matris a hast ya na(ye row dare ye col ba n ke jash dar araye ast)
			{
				while (getRowX(n) == i)
				{
					int m = sp2.findInCols(j,getRowY(n));
					if (m != -1)
					{
						sum += getRowValue(n)*sp2.getRowValue(m);
						//cout <<"\nC["<<i<<"]["<<j<<"] = a("<<n<<")*b("<<m<<")";
					}
					n++;
				}

				if (sum != 0)
				{
					res.cells[count].setCell(i,j,sum);
					count++;
				}

			}//if n != -1
		}
	}//for i

	return res;
	
}

int Sparce::findInRows(int i)
{
	for (int j = 0; j < getValue(); j++)
		if(getRowX(j) == i)
			return j;

	return -1;
}
int Sparce::findInCols(int soton,int satr)
{
	/*
	alan aval check mikonim ke satr i om dar matris a hast ya na(ye row dare ye col=satr ba n ke jash dar araye ast)
	agar satr i om bood bayad begardim bebinim sotoon j=soton om dar matris b hast ya na
	agar unam bood , migardim bebinim aya col dar satr haye b hast ya na

	*/	

	for (int j = 0; j < getValue(); j++) 
		if(getRowX(j) == satr && getRowY(j) == soton)
			return j;

	return -1;
}

Sparce  Sparce::transpose()
{
	Sparce b(this->getRow(),this->getCol(),this->getValue());
	int currentb = -1;

	for (int i = 0; i < this->getCol(); i++)
		for (int j = 0; j < this->getValue(); j++)
			if(this->getRowY(j) == i)
				b.cells[++currentb].setCell(getRowY(j),getRowX(j),getRowValue(j));

	return b;
}

Sparce Sparce::quickTranspose()
	{
		int * rowSize = new int[getCol()];
		int * rowStart = new int[getCol()];

		for (int i = 0; i < getCol(); i++)
			rowSize[i] = 0 ; //meghdar avaliye rowSize ha bayad sefr bashe ta har bar ++ beshe

		for (int i = 0; i < getValue(); i++)
			rowSize[cells[i].getCol()]++;//tedad anasor har sotoon ro mishmare , masalan mige soton2 , 3 bar tekrar shode(too col ha 3 bar 2 umade) , inja meghdar rowSize[2] mishe 3

		rowStart[0] = 0;//mogheyat satr 0 matris b(javab) hamoon 0 hast (tozih bishtar dar halghe baad)

		for (int i = 1; i < getCol(); i++)
			rowStart[i] = rowStart[i-1]+rowSize[i-1];//moghe'eeyat shoroo satr i dar b (soton i dar a) , yani az cells chand 2 ha shoroo mishe
			//masalan : 1 --->moghee'yat satr0 ke 0 hast ba farz inke 4 ta ham 0 dashte bashim 1 az 4 bayad shoroo beshe
			//masalan : 2 --->moghee'yat satr1 ke 4 hast ba farz inke 3 ta ham 1 dashte bashim 2 az 7 bayad shoroo beshe


		Sparce b(getCol(),getRow(),getValue());//matris javab

		int j;//baraye taskkhis moghee'yat dar matis b(javab)

		for (int i = 0; i < getValue(); i++) 
		{
			// be tedad value ha mirim har bar jaye har value ro dar roe start peyda mikonim va mizarim too j --->masalan satr 2 az 7 shoroo shode
			j = rowStart[cells[i].getCol()]++; // har bar j++ mishe ke mogheyat baadi ro dashte bashe , masalan 2 aval bayad dar moghe'eeyat 8 bashe 2 baadi dar 9 va 2 baadi dar 10
			b.cells[j].setCell(cells[i].getCol(),cells[i].getRow(),cells[i].getValue());//meghdar satr dar soton va soton dar satr
		}

		delete[] rowStart;
		delete[] rowSize;
		return b;
	}

std::ostream & operator <<(std::ostream& os, Sparce & sprc)
{
	const char khate_bala=(char)196;
	const char t = (char)194; // esm be khatere ghiyafe shabih be T
	const char vasat =(char) 197;
	const char khate_saf = (char)179;


	os << sprc.row <<setw(4) << khate_saf << sprc.col <<setw(4) << khate_saf<<sprc.value<<endl;
	os<< khate_bala<<khate_bala<<khate_bala <<khate_bala<<vasat<< khate_bala<<khate_bala<<khate_bala <<khate_bala<<vasat<< khate_bala<<khate_bala<<khate_bala <<khate_bala<<endl;
	os <<setw(4)<< "Rows"  << khate_saf <<setw(4)<< "Cols"  << khate_saf<<"Vals"<<endl;

	for (int i = 0; i < sprc.value; i++)
	{
		os<< khate_bala<<khate_bala<<khate_bala <<khate_bala<<vasat<< khate_bala<<khate_bala<<khate_bala <<khate_bala<<vasat<< khate_bala<<khate_bala<<khate_bala <<khate_bala<<endl;
		os<<sprc.cells[i].getRow() <<setw(4) << khate_saf << sprc.cells[i].getCol() <<setw(4) << khate_saf<<sprc.cells[i].getValue()<<endl;
	}

	return os;
}

