using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int nAttack;
    public int nHP;
    public int nExp;
    public int nLv = 1;

    public int nHPMax;

    public GUIStatusBar guiHPBar;
    public GUIStatusBar guiExpBar;

    private void Start()
    {
        nHPMax = nHP;
    }

    private void Update()
    {
        if (guiHPBar) guiHPBar.SetStatus(nHP, nHPMax);
        if (guiExpBar) guiExpBar.SetStatus(nExp, 100);

        if (Death())
        {
            Destroy(this.gameObject);
        }
        LvUp();
    }

    public void LvUp()
    {
        if(nExp >= 100)
        {
            nLv++;
            nAttack += 10;
            nHP += 10;
            nHPMax += 10;
            nExp -= 100;
        }
    }

    public void StillExp(Player target)
    {
        nExp += target.nLv * 100 + target.nExp;
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
        Debug.Log("####" + this.gameObject.name + "####");
        Debug.Log("HP:" + nHP);
        Debug.Log("ATK:" + nAttack);
        Debug.Log("Lv/Exp:" + nLv + "/" + nExp);
    }

    public int idx = 0;
    //private void OnGUI()
    //{
    //    int w = 100;
    //    int h = 20;
    //    GUI.Box(new Rect(w*idx,0,w,h),"####" + this.gameObject.name + "####");
    //    GUI.Box(new Rect(w*idx, 20, w, h),"HP:" + nHP);
    //    GUI.Box(new Rect(w*idx, 40, w, h),"ATK:" + nAttack);
    //    GUI.Box(new Rect(w * idx, 60, w, h), "Lv/Exp:" + nLv + "/" + nExp);
    //}
}
