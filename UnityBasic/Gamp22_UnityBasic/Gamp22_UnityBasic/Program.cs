using System;
using System.Collections.Generic;

namespace Gamp22_UnityBasic
{
    class Player
    {
        string strName;
        int nAttack;
        int nHP;

        public Player(string name, int hp, int atk)
        {
            strName = name;
            nAttack = atk;
            nHP = hp;
        }

        public void Attack(Player target)
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
            Console.WriteLine("####" + strName + "####");
            Console.WriteLine("HP:"+nHP);
            Console.WriteLine("ATK:" + nAttack);
        }
    }

    class Program
    {
        static void ClassBattleClassMain()
        {
            Player player = new Player("player",100,10);
            Player monster = new Player("slime",20,5);
            List<Player> listMonster = new List<Player>();

            listMonster.Add(monster);
            listMonster.Add(new Player("skeleton", 50, 10));
            listMonster.Add(new Player("zombie", 100, 15));
            listMonster.Add(new Player("dragon", 200, 50));

            while (true)
            {
                if (player.Death() == false)
                {
                    player.Attack(monster);
                    monster.Show();
                }
                else break;

                if (monster.Death() == false)
                {
                    monster.Attack(player);
                    player.Show();
                }
                else break;
            }
        }

        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            //ValMain();
            //PlayerAttackMain();
            //CritcalAttackMain();
            //StageMain();
            //AttackWhile(); //보고싶지않으면 //를 앞에 넣는다.
            //MonsterListMain();
            //BattleMain();
            ClassBattleClassMain();
        }

        static void ValMain()
        {
            int nScore = 0;
            float fRat = 1.0f / 4.0f;//0.25
            Console.WriteLine("Score:" + nScore);
            Console.WriteLine("Rat:" + fRat);
        }
        //변수: 데이터를 저장하는 공간
        //데이터타입: 데이터의 종류를 지정하는것. ex) int,float,bool...
        //플레이어가 몬스터를 공격한다.
        //(플레이어의 공격력)만큼 (몬스터의 hp)를 감소시킨다.(단, 몬스터의hp는 100이고, 플레이어의 공격력은 10이다)
        //계산전의 변수값과 계산후의 변수값을 비교하여 정상적으로 작동된지 확인해야한다.
        static void PlayerAttackMain()
        {
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            Console.WriteLine("1.MonsterHP:" + nMonsterHP);
            Console.WriteLine("1.PlayerAttack:" + nPlayerAttack);
            nMonsterHP = nMonsterHP - nPlayerAttack;
            Console.WriteLine("2.MonsterHP:" + nMonsterHP);
            Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
        }
        //플레이어가 몬스터를 치명타로 공격했다.
        //치명타? 일정확률로 추가데미지가 발생한다.(일정비율로)
        static void CritcalAttackMain()//1.함수를 먼저 생성하고
        {
            int nPlayerAttack = 10;
            int nMonsterHP = 100;
            Console.WriteLine("1.MonsterHP:" + nMonsterHP);
            Console.WriteLine("1.PlayerAttack:" + nPlayerAttack);
            Random cRandom = new Random();//임의 의값을 꺼낼 상자를 준비한다.
            //상자에 준비할 공의 종류를 지정한다.
            int nRandom = cRandom.Next(0, 4);//프로그래밍에서는 보통 0부터 시작해서 n-1개까지 숫자를 지정한다. ex)0~3:0,1,2/1~3:1,2/1~4:1,2,3
            Console.WriteLine("1.Random:" + nRandom);
            if (nRandom == 3)
            {
                nMonsterHP = nMonsterHP - nPlayerAttack * 2;
                Console.WriteLine("Critcal Attack!!");
            }
            else
            {
                nMonsterHP = nMonsterHP - nPlayerAttack;
            }
            Console.WriteLine("2.MonsterHP:" + nMonsterHP);
            Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
        }
        //텍스트게임에서 플레이어가 해당위치를 선택하면 어느 위치에 도착했는지 알수있도록 만들기
        //1.플레이어가 어떤 장소에 있는지 저장하는 변수를 준비한다.
        //2.준비된 변수에 이동할 장소를 입력받는다. 
        //3.입력받은 변수의 값에 따라 어떤 장소에 방문한지 출력한다.
        static void StageMain()
        {
            string strInput;
            Console.WriteLine("어느장소를 방문하시겠습니까? (마을, 필드, 상점)");
            strInput = Console.ReadLine();
            switch(strInput)
            {
                case "마을":
                    Console.WriteLine("마을 입니다.");
                    break;
                case "필드":
                    Console.WriteLine("마을 입니다.");
                    break;
                case "상점":
                    Console.WriteLine("상점 입니다.");
                    break;
                default:
                    Console.WriteLine("이동할 수 없습니다..");
                    break;
            }
        }
        //플레이어가 몬스터를 죽을때까지 공격한다.
        //죽음? 몬스터의 hp가 0보다 작거나 같을때 공격을 중단한다.
        static void AttackWhile()
        {
            int nPlayerAttack = 15;
            int nMonsterHP = 100;
            Console.WriteLine("1.MonsterHP:" + nMonsterHP);
            Console.WriteLine("1.PlayerAttack:" + nPlayerAttack);
            //while (true)
            //while (nMonsterHP <= 0) //100 <= 0 -> 거짓
            //몬스터가 살아있으면,
            while (nMonsterHP > 0) //100 <= 0 -> 거짓
            {
                if (nMonsterHP <= 0) break;
                nMonsterHP = nMonsterHP - nPlayerAttack;//공격한다.
                Console.WriteLine("2.MonsterHP:" + nMonsterHP);
                Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
            }
        }
        //(단, 플레이어와 몬스터의hp는 100이고, 공격력은 10이다)
        //플레이어가 몬스터를 공격한다.
        //(플레이어의 공격력)만큼 (몬스터의 hp)를 감소시킨다.
        //몬스터가 플레이어에게 반격한다.
        //(몬스터의 공격력)만큼 (플레이어의 hp)를 감소시킨다.
        //둘중 한명이 사망하면 끝난다. -> 플레이어나 몬스터의 hp가 0이하가되면
        //몬스터가 죽었지만, 공격해서 플레이어도 사망했다 -> 죽으면 공격할수 없다.
        static void BattleMain()
        {
            int nPlayerAttack = 20;
            int nPlayerHP = 100;

            int nMonsterAttack = 20;
            int nMonsterHP = 100;
            //플레이어가 죽었거나 몬스터가 죽었을때
            //20 <= 0 -> 거짓 || 0 <= 0 ->참 -> 참 -> 참
            //20 <= 0 -> 거짓 && 0 <= 0 ->참 -> 참 -> 거짓
            //플레이어나 몬스터가 둘다 살아아있을때 전투한다.
            while (nPlayerHP >0 && nMonsterHP > 0)
            {
                if (nPlayerHP > 0) //20
                {
                    nMonsterHP = nMonsterHP - nPlayerAttack;//공격한다. //20 - 20 = 0
                    Console.WriteLine("2.PlayerAttack:" + nPlayerAttack);
                    Console.WriteLine("2.MonsterHP:" + nMonsterHP);
                }
                //else break;
                if (nMonsterHP > 0)
                {
                    nPlayerHP = nPlayerHP - nMonsterAttack;//반격한다. 
                    Console.WriteLine("2.MonsterAttack:" + nPlayerAttack);
                    Console.WriteLine("2.PlayerHP:" + nPlayerHP);
                }
                //else  break;
            }
        }
        //몬스터를 리스트에 저장하고, 각 리스트의 첫번째값과 마지막값을 출력하고, 모든 리스트의 값을 출력하여라.(단, 슬라임,스켈레톤,좀비,드래곤)
        static void MonsterListMain()
        {
            List<string> listMonster = new List<string>();
            listMonster.Add("Slime"); //0
            listMonster.Add("Skeleton"); //1
            listMonster.Add("Zombie"); //2
            listMonster.Add("Dragon"); //3

            Console.WriteLine(listMonster[0]);
            Console.WriteLine(listMonster[3]);

            for(int i = 0;  i < listMonster.Count; i++)
            {
                Console.WriteLine(i+":"+listMonster[i]);
            }
        }
    }
}
