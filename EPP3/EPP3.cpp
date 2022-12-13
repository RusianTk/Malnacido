//Examen 

#include <iostream>
using namespace std;

class Pet
{
public:
    Pet(int hunger = 0, int boredom = 0, int life = 10, bool isDeath = false);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Health(int medicine = 5);
    void Stats();
    bool m_isDeath;
    void Death();
private:
    int m_Hunger;
    int m_Boredom;
    int m_Life;
    int GetMood() const;
    void PassTime(int time = 1);
};


Pet::Pet(int hunger, int boredom, int life, bool isDeath) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Life(life),
    m_isDeath(isDeath)

{}

void Pet::Death()
{
    if (m_Life == 0)
    {
        cout << "\nMe dio cancer \n Tu mascota murio \n";
        m_isDeath = true;
    }
}

void Pet::Stats()
{
    cout << "Hambre: " << m_Hunger << endl;
    cout << "Aburrimiento: " << m_Boredom<< endl;
    cout << "Salud: " << m_Life << endl;
}

void Pet::Health(int medicine)
{
    cout << "\Glup. \n";
    m_Life += medicine;

    if (m_Life > 10)
    {
        m_Life = 10;
    }

    PassTime();
}

inline int Pet::GetMood() const
{
    return (m_Hunger + m_Boredom);
}

void Pet::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_Life -= time;
}

void Pet::Talk()
{
    cout << "\n\n Humano estoy: ";
    int mood = GetMood();

    if (mood > 10)
    {
        cout << "mal. \n";
    }
    else if (mood > 5)
    {
        cout << "ok. \n";
    }
    else {
        cout << "feliz. \n";
    }

    cout << "\n\n Y mi salud es: ";
    int li = m_Life;

    if (li == 10)
    {
        cout << "Excelente \n";
    }
    else if (li > 4 && li < 10)
    {
        cout << "Ok. \n";
    }
    else if (li > 1 && li < 5 )
    {
        cout << "Me voy a morir. \n";
    }
 

    if (m_Hunger > 5)
    {
        cout << "Tengo hambre \n";
    }
    if (m_Boredom > 5)
    {
        cout << "Estoy aburrido \n";
    }
    if (m_Life < 5)
    {
        cout << "Necesito medicina, estoy enfermo. \n";
    }


    PassTime();
}

void Pet::Eat(int food)
{
    cout << "\Brrup. \n";
    m_Hunger -= food;

    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }

    PassTime();
}

void Pet::Play(int fun)
{
    cout << "\n Wheeee \n";
    m_Boredom -= fun;

    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }

    PassTime();
}


int main()
{

    Pet pet;
    pet.Talk();
    int choice;

    do {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 -  Salir\n";
        cout << "1 -  Escucha a tu macota\n";
        cout << "2 -  Alimentar\n";
        cout << "3 -  Jugar con mascota\n";
        cout << "4 -  Curar mascota\n";
        cout << "5 -  Estadisticas\n";
        cout << "Elige una opción: \n";

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!. \n";
            break;
        case 1:
            pet.Talk();
            break;
        case 2:
            pet.Eat();
            break;
        case 3:
            pet.Play();
            break;
        case 4:
            pet.Health();
            break;
        case 5:
            pet.Stats();
            break;
        default:
            cout << "\nTu elección se inválida. \n";
        }

        pet.Death();

        if (pet.m_isDeath)
        {
            break;
        }


    } while (choice != 0);
}