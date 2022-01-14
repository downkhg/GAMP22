using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Gamp22_UnityBasic
{
    class Tranner
    {
        List<Pokemon> pokemons;

        public void Catch(Pokemon pokemon)
        {
            pokemons.Add(pokemon);
        }

        public Pokemon Throw(string name)
        {
            Pokemon returnPokemon = pokemons.Find(pokemon => pokemon.StrName == name);
            pokemons.Remove(returnPokemon);
            return returnPokemon;
        }
    }
    class Pokemon
    {
        string strName;
        int nAttack;
        int nHP;

        public string StrName { get => strName; set => strName = value; }

        public Pokemon(string name, int hp, int atk)
        {
            StrName = name;
            nAttack = atk;
            nHP = hp;
        }

        public void Attack(Pokemon target)
        {
            target.nHP -= this.nAttack;
        }

        public bool Death()
        {
            if (nHP > 0) return false;
            else return true;
        }

        public void Show()
        {
            Console.WriteLine("####" + StrName + "####");
            Console.WriteLine("HP:" + nHP);
            Console.WriteLine("ATK:" + nAttack);
        }
    }

    class PokemonGame
    {
    }
}
