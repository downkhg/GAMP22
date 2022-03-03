using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIPlayerInfo : MonoBehaviour
{
    public Text textName;
    public Text textLv;
    public GUIStatusBar guiHPBar;
    public GUIStatusBar guiExpBar;

    public void Set(GameObject obj)
    {
        Player player = obj.GetComponent<Player>();

        if (player)
        {
            textName.text = obj.name;
            textLv.text = string.Format("Lv.{0}", player.nLv);
            guiHPBar.SetStatus(player.nHP, player.nHPMax);
            guiExpBar.SetStatus(player.nExp, 100);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
