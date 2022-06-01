//추상화
//좌표(벡터):도형의 좌표를 2차원에서 나타내기위한 객체
//도형: 동작:그리기 //인터페이스
//삼각형: 속성:좌표x3 동작:그리기
//사각형: 속성:좌표x4 동작:그리기
//원: 속성:좌표,반지름 동작:그리기
#include <iostream>
using namespace std;

namespace Inheritance
{
	class Vihicle
	{
	protected: //자식은 접근가능하고 외부에서 접근불가.
		int m_nGear = 0;
		int m_nSpeed = 0;
		int m_nSeats = 1;
	public:
		Vihicle(int seat = 1)
		{
			cout << "Vihicle[" << this << "]:" << sizeof(*this) << endl;
			m_nSeats = seat;
		}
		~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

		void Accel() { m_nSpeed++; }
		void Break() { m_nSpeed--; }
		void SetGear(int gear) { m_nGear = gear; }
		int GetGear() { return m_nGear; }
		//void SetSeats(int seat) { m_nSeats = seat; }
	};

	class Bike : public Vihicle
	{
	public:
		Bike() { cout << "Bike[" << this << "]:" << sizeof(*this) << endl; }
		~Bike() { cout << "~Bike[" << this << "]:" << endl; }
	};

	class AutoBike : public Vihicle
	{
		int m_nEngine;
	public:
		AutoBike(int engine = 300)
		{
			cout << "AutoBike[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Vihicle
	{
		int m_nEngine;
		int m_nMaxWight;
	public:
		Track(int engine = 3000, int wight = 1000)
		{
			cout << "Track[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			m_nMaxWight = wight;
		}
		~Track() { cout << "~Track[" << this << "]" << endl; }
	};

	class Bus : public Vihicle
	{
		int m_nEngine;
	public:
		Bus(int engine = 7000, int seat = 30) :Vihicle(seat)//부모생성자의 호출: 생성자를 통해 호출하면 부모멤버의 접근제어자와 상관없이 사용가능.
		{
			cout << "Bus[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //부모멤버가 private가 아니여야 접근가능.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};

	void CarMain()
	{
		Vihicle cVihvle;
		Bike cBike;
		AutoBike cAutoBike;
		Track cTrack;
		Bus cBus;
	}
}

//계층상속: 부모를 가진클래스를 상속받는것.
namespace HierarchyInheritance
{
	class Vihicle
	{
	protected: //자식은 접근가능하고 외부에서 접근불가.
		int m_nGear = 0;
		int m_nSpeed = 0;
		int m_nSeats = 1;
	public:
		Vihicle(int seat = 1)
		{
			cout << "Vihicle[" << this << "]:" << sizeof(*this) << endl;
			m_nSeats = seat;
		}
		~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

		void Accel() { m_nSpeed++; }
		void Break() { m_nSpeed--; }
		void SetGear(int gear) { m_nGear = gear; }
		void SetSeats(int seat) { m_nSeats = seat; }
	};

	class Eneginer : Vihicle
	{
	protected:
		int m_nEngine;
	public:
		Eneginer(int engine = 300)
		{
			cout << "Eneginer[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
		}
		~Eneginer()
		{
			cout << "~Eneginer[" << this << "]" << endl;
		}
	};

	class AutoBike : public Eneginer
	{
	public:
		AutoBike(int engine = 300) : Eneginer(engine)
		{
			cout << "AutoBike[" << this << "]:" << sizeof(*this) << endl;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Eneginer
	{
		int m_nMaxWight;
	public:
		Track(int engine = 3000, int wight = 1000)
		{
			cout << "Track[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			m_nMaxWight = wight;
		}
		~Track() { cout << "~Track[" << this << "]" << endl; }
	};

	class Bus : public Eneginer
	{
	public:
		Bus(int engine = 7000, int seat = 30) :Eneginer(engine)//부모생성자의 호출: 생성자를 통해 호출하면 부모멤버의 접근제어자와 상관없이 사용가능.
		{
			//Vihicle(seat); //다음과같이 처리하면 임시객체만들기때문에 초기화가 아니다.
			//m_nSeats = seat; //기능적으로 같지만 초기화가 부모에서 이미 이루어졌다,
			cout << "Bus[" << this << "]" << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //부모멤버가 private가 아니여야 접근가능.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};

	void CarMain()
	{
		Vihicle cVihicle;
		//Bike cBike; //멤버가 추가되지않으므로 굳이 클래스로 만들필요가없다.
		//만약 자전거를 만든다면 객체를 다르게 표현하는것이 방법일수있다.
		Vihicle cBike;
		Eneginer cAutoBike;
		//AutoBike cAutoBike;
		Track cTrack;
		Bus cBus;
		cout << "#### Size #####" << endl;
		cout << "Vihicle:" << sizeof(cVihicle) << endl;
		cout << "Engener:" << sizeof(cAutoBike) << endl;
		cout << "Track:" << sizeof(cTrack) << endl;
		cout << "Bus:" << sizeof(cBus) << endl;
	}
}

namespace DiamondInheritance
{
	class Vihicle
	{
	protected: //자식은 접근가능하고 외부에서 접근불가.
		int m_nGear = 0;
		int m_nSpeed = 0;
		int m_nSeats = 1;
	public:
		Vihicle(int seat = 1)
		{
			cout << "Vihicle[" << this << "]:" << sizeof(*this) << endl;
			m_nSeats = seat;
		}
		~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

		void Accel() { m_nSpeed++; }
		void Break() { m_nSpeed--; }
		void SetGear(int gear) { m_nGear = gear; }
		void SetSeats(int seat) { m_nSeats = seat; }
	};

	class Bike : public Vihicle
	{
	public:
		Bike() { cout << "Bike[" << this << "]:" << sizeof(*this) << endl; }
		~Bike() { cout << "~Bike[" << this << "]:" << endl; }
	};

	class Eneginer : Vihicle
	{
	protected:
		int m_nEngine;
	public:
		Eneginer(int engine = 300)
		{
			cout << "Eneginer[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
		}
		~Eneginer()
		{
			cout << "~Eneginer[" << this << "]" << endl;
		}
	};

	class AutoBike : public Bike, public Eneginer
	{
	public:
		AutoBike(int engine = 300) : Eneginer(engine)
		{
			cout << "AutoBike[" << this << "]:" << sizeof(*this) << endl;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Eneginer
	{
		int m_nMaxWight;
	public:
		Track(int engine = 3000, int wight = 1000)
		{
			cout << "Track[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			m_nMaxWight = wight;
		}
		~Track() { cout << "~Track[" << this << "]" << endl; }
	};

	class Bus : public Eneginer
	{
	public:
		Bus(int engine = 7000, int seat = 30) :Eneginer(engine)//부모생성자의 호출: 생성자를 통해 호출하면 부모멤버의 접근제어자와 상관없이 사용가능.
		{
			//Vihicle(seat); //다음과같이 처리하면 임시객체만들기때문에 초기화가 아니다.
			//m_nSeats = seat; //기능적으로 같지만 초기화가 부모에서 이미 이루어졌다,
			cout << "Bus[" << this << "]" << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //부모멤버가 private가 아니여야 접근가능.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};

	void CarMain()
	{
		Vihicle cVihicle;
		Bike cBike; //멤버가 추가되지않으므로 굳이 클래스로 만들필요가없다.
		//만약 자전거를 만든다면 객체를 다르게 표현하는것이 방법일수있다.
		//Vihicle cBike;
		//Eneginer cAutoBike;
		AutoBike cAutoBike;
		Track cTrack;
		Bus cBus;
		cout << "#### Size #####" << endl;
		cout << "Vihicle:" << sizeof(cVihicle) << endl;
		cout << "Engener:" << sizeof(cAutoBike) << endl;
		cout << "Track:" << sizeof(cTrack) << endl;
		cout << "Bus:" << sizeof(cBus) << endl;
	}
}

class Spiker
{
	bool m_bPower;
	float m_fVolume;
public:
	Spiker()
	{
		m_bPower = false;
		m_fVolume = 0;
	}
	void SwitchOn()
	{
		m_bPower = true;
	}
	void SwitchOff()
	{
		m_bPower = false;
	}
	void VolumeUp()
	{
		m_fVolume++;
	}
	void VolumeDown()
	{
		m_fVolume--;
	}
};

class Antena
{
	float m_fHertz;
public:
	void HertzUp()
	{
		m_fHertz++;
	}
	void HertzDown()
	{
		m_fHertz--;
	}
};
namespace IsA
{
	//is-a: 상속을 이용하면 코드를 거이 작성하지않고 만들수있다.
	class Radio : public Spiker, public Antena
	{

	};

	void RadioMain()
	{
		Radio cRadio; //라디오를 만들수있다. 그러나 내부부품은 재활용할수없다.
	}
}
namespace HasA
{
	//has-a: 각 객체를 감싸는 함수를 만들어한다.
	//만들때 내부의 부품을 더 좋은 부품을 사용할수있다.
	//(현실에 라디오라면 직접 인터페이스를 내부에 보드에 연결하므로 여기에 해당될수도 있다.)
	class Radio
	{
		Spiker* m_pSpiker;
		Antena* m_pAntena;
	public:
		Radio(Spiker* spiker, Antena* antena)
		{
			m_pSpiker = spiker;
			m_pAntena = antena;
		}
		void SwitchOn()
		{
			m_pSpiker->SwitchOn();
		}
		void SwitchOff()
		{
			m_pSpiker->SwitchOff();
		}
		void VolumeUp()
		{
			m_pSpiker->VolumeUp();
		}
		void VolumeDown()
		{
			m_pSpiker->VolumeDown();
		}
		void HertzUp()
		{
			m_pAntena->HertzUp();
		}
		void HertzDown()
		{
			m_pAntena->HertzDown();
		}
	};

	void RadioMain()
	{
		Spiker* pSpiker = new Spiker();
		Antena* pAntena = new Antena();

		//라디오를 조립할때 부품을 선택할수있고, 재활용이 가능하다.
		Radio cRadio(pSpiker, pAntena);
		cRadio.SwitchOn();
		cRadio.VolumeUp();
		cRadio.HertzDown();
		cRadio.SwitchOff();

		delete pSpiker;
		delete pAntena;
	}
}

void main()
{
	//ShapeMain();
	//Inheritance::CarMain();
	//HierarchyInheritance::CarMain();
	//DiamondInheritance::CarMain();
	HasA::RadioMain();
	IsA::RadioMain();
}