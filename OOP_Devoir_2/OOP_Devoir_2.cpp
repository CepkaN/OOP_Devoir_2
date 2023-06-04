#include<iostream>
#include<string>
#include<vector>

class Persona {
private:
	std::string _FIO;
	int _eta;
	std::string _attivita;
public:
	Persona(std::string FIO,int eta,std::string attivita):_FIO(FIO),_eta(eta),_attivita(attivita) {}
	Persona() {
		_FIO = "niente";
		_eta = 0;
		_attivita = "niente";
	}
	~Persona(){
		delete(this);
	}
	virtual void Mostrare() {
		std::cout << "ФИО жильца : " << this->_FIO << '\n';
		std::cout << "Возраст : " << this->_eta << '\n';
		std::cout << "Деятельность : " << this->_attivita << '\n';
	}
};
class Appartamento :public Persona{
private:
	std::vector<Persona*>pers;
	int num=0;
	int camera=0;
public:
	Appartamento(int n, int c, std::vector<Persona*>per) {
		this->pers = per; this->num = n; this->camera = c;
	}
	Appartamento(){}
	~Appartamento() {
		delete(this);
	}
	int Numero() {
		return num;
	}
	int Camera() {
		return camera;
	}
	void Mostrare1(){
		std::cout << "\n\nКоличество комнат : " << num << '\n';
		std::cout << "Номер квартиры : " << camera << '\n';
		for (const auto& it : pers) {
			it->Mostrare();
		}
	}
};
class Casa :public Appartamento {
private:
	std::vector<Appartamento*>appart;
	std::string _Adresse;
public:
	Casa(std::string Adr, std::vector<Appartamento*>&App) {
		this->_Adresse = Adr; this->appart = App;
	}
	~Casa() {
		delete(this);
	}
	std::string Ad() {
		return _Adresse;
	}
	void Mostrare2() {
		std::cout << "Адрес : " << _Adresse <<'\n';
		for (const auto& it1 : appart)
			it1->Mostrare1();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	

	Persona* persona1 = new Persona("Oleand", 34, "proger");
	Persona* persona2 = new Persona("Tanya", 65, "dentista");
	Persona* persona3 = new Persona("Ivan", 21, "giardiniere");
	std::vector<Persona*>per = { persona1,persona2,persona3 };
	Persona* persona4 = new Persona("Sonya", 35, "oculista");
	Persona* persona5 = new Persona("Aslan", 29, "venditore");
	Persona* persona6 = new Persona("Ars", 7, "scolaro");
	std::vector<Persona*>per1 = { persona4,persona5,persona6 };
	Appartamento* appartamento1 = new Appartamento( 5, 55,per);
	Appartamento* appartamento2 = new Appartamento(7, 77, per1);
	std::vector<Appartamento*>app = { appartamento1,appartamento2 };
	Casa* casa = new Casa("Vologodina 17/a", app);
	casa->Mostrare2();


	return 0;
}