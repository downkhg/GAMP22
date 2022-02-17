using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public int nAttack;
    public int nHP;

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
    }

    public int idx = 0;
    private void OnGUI()
    {
        int w = 100;
        int h = 20;
        GUI.Box(new Rect(w*idx,0,w,h),"####" + this.gameObject.name + "####");
        GUI.Box(new Rect(w*idx, 20, w, h),"HP:" + nHP);
        GUI.Box(new Rect(w*idx, 40, w, h),"ATK:" + nAttack);
    }
}
