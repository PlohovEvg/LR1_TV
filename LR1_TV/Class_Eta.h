#pragma once
class Eta
{
	int value;
	int ni;
	double p;
public:
	Eta():value(1),ni(1){}
	int GetValue() { return this->value; }
	int GetNi() { return this->ni; }
	double GetP() { return this->p; }
	void IncValue() { this->value++; }
	void IncNi() { this->ni++; }
	void SetValue(int k) { this->value = k; }
	void SetP(double _p) { this->p = _p; }
	bool operator==(Eta &e)
	{
		if (this->value == e.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator <(Eta &e)
	{
		if (this->value < e.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator >(Eta &e)
	{
		if (this->value > e.value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Eta& operator =(const Eta &e)
	{
		value = e.value;
		ni = e.ni;
		p = e.p;

		return *this;
	}
};