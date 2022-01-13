using System;

namespace Gamp22_UnityBasic
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello World!");
            //ValMain();
            //PlayerAttackMain();
            //CritcalAttackMain();
            //StageMain();
            //AttackWhile(); //보고싶지않으면 //를 앞에 넣는다.
            //MonsterListMain();
            StageMain();
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
            int nRandom = cRandom.Next(0, 3);//프로그래밍에서는 보통 0부터 시작해서 n-1개까지 숫자를 지정한다. ex)0~3:0,1,2/1~3:1,2
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

        static void AttackWhile()
        {
            
        }

        static void MonsterListMain()
        {

        }
    }
}
