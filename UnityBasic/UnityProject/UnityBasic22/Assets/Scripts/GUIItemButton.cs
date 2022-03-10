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
        }
        else
            Debug.LogError("GUIItemButton Set Faild!!");
    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("GUIItemButton::Start");
        Set(Item.E_ITEM_KIND.SUPER);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
