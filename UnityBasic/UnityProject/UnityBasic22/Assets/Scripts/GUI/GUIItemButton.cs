using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemButton : MonoBehaviour
{
    public Image imgIcon;
    public Text textName;

    public void Set(Item.E_ITEM_KIND eItemKind)
    {
        ItemInfo  itemInfo = GameManager.GetInstance().ItemManager.GetItemInfo(eItemKind);
        
        if (itemInfo != null)
        {
            imgIcon.sprite = Resources.Load<Sprite>("Icon/" + itemInfo.icon);
            textName.text = itemInfo.name;
            Button button = GetComponent<Button>();
            GameObject objTarget = GameManager.GetInstance().responnerPlayer.objPlayer;
            button.onClick.AddListener(() => Item.Use(objTarget, itemInfo));
        }
        else
            Debug.LogError("GUIItemButton Set("+eItemKind+") Faild!!");
    }

    public void Set(ItemInfo itemInfo)
    {
        if (itemInfo != null)
        {
            imgIcon.sprite = Resources.Load<Sprite>("Icon/" + itemInfo.icon);
            textName.text = itemInfo.name;
            Button button = GetComponent<Button>();
            GameObject objTarget = GameManager.GetInstance().responnerPlayer.objPlayer;
            button.onClick.AddListener(() => Item.Use(objTarget, itemInfo));
        }
        else
            Debug.LogError("GUIItemButton Set("+itemInfo.name+") Faild!!");
    }

    ////테스트코드
    //public Item.E_ITEM_KIND eItemTest;
    //// Start is called before the first frame update
    //void Start()
    //{
    //    Debug.Log("GUIItemButton::Start");
    //    Set(eItemTest);
    //}
}
