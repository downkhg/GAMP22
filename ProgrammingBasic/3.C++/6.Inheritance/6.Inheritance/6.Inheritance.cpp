//�߻�ȭ
//��ǥ(����):������ ��ǥ�� 2�������� ��Ÿ�������� ��ü
//����: ����:�׸��� //�������̽�
//�ﰢ��: �Ӽ�:��ǥx3 ����:�׸���
//�簢��: �Ӽ�:��ǥx4 ����:�׸���
//��: �Ӽ�:��ǥ,������ ����:�׸���
#include <iostream>
using namespace std;

namespace Inheritance
{
	class Vihicle
	{
	protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
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
		Bus(int engine = 7000, int seat = 30) :Vihicle(seat)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
		{
			cout << "Bus[" << this << "]:" << sizeof(*this) << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
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

//�������: �θ� ����Ŭ������ ��ӹ޴°�.
namespace HierarchyInheritance
{
	class Vihicle
	{
	protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
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
		Bus(int engine = 7000, int seat = 30) :Eneginer(engine)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
		{
			//Vihicle(seat); //���������� ó���ϸ� �ӽð�ü����⶧���� �ʱ�ȭ�� �ƴϴ�.
			//m_nSeats = seat; //��������� ������ �ʱ�ȭ�� �θ𿡼� �̹� �̷������,
			cout << "Bus[" << this << "]" << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};

	void CarMain()
	{
		Vihicle cVihicle;
		//Bike cBike; //����� �߰����������Ƿ� ���� Ŭ������ �����ʿ䰡����.
		//���� �����Ÿ� ����ٸ� ��ü�� �ٸ��� ǥ���ϴ°��� ����ϼ��ִ�.
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
	protected: //�ڽ��� ���ٰ����ϰ� �ܺο��� ���ٺҰ�.
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
		Bus(int engine = 7000, int seat = 30) :Eneginer(engine)//�θ�������� ȣ��: �����ڸ� ���� ȣ���ϸ� �θ����� ���������ڿ� ������� ��밡��.
		{
			//Vihicle(seat); //���������� ó���ϸ� �ӽð�ü����⶧���� �ʱ�ȭ�� �ƴϴ�.
			//m_nSeats = seat; //��������� ������ �ʱ�ȭ�� �θ𿡼� �̹� �̷������,
			cout << "Bus[" << this << "]" << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //�θ����� private�� �ƴϿ��� ���ٰ���.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};

	void CarMain()
	{
		Vihicle cVihicle;
		Bike cBike; //����� �߰����������Ƿ� ���� Ŭ������ �����ʿ䰡����.
		//���� �����Ÿ� ����ٸ� ��ü�� �ٸ��� ǥ���ϴ°��� ����ϼ��ִ�.
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
	//is-a: ����� �̿��ϸ� �ڵ带 ���� �ۼ������ʰ� ������ִ�.
	class Radio : public Spiker, public Antena
	{

	};

	void RadioMain()
	{
		Radio cRadio; //������ ������ִ�. �׷��� ���κ�ǰ�� ��Ȱ���Ҽ�����.
	}
}
namespace HasA
{
	//has-a: �� ��ü�� ���δ� �Լ��� ������Ѵ�.
	//���鶧 ������ ��ǰ�� �� ���� ��ǰ�� ����Ҽ��ִ�.
	//(���ǿ� ������� ���� �������̽��� ���ο� ���忡 �����ϹǷ� ���⿡ �ش�ɼ��� �ִ�.)
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

		//������ �����Ҷ� ��ǰ�� �����Ҽ��ְ�, ��Ȱ���� �����ϴ�.
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