using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class GUIItemButton : MonoBehaviour, IPointerExitHandler, IPointerEnterHandler
{
    public Image imgIcon;
    public Text textName;
    ItemInfo itemInfo;

    public void Set(Item.E_ITEM_KIND eItemKind)
    {
        ItemInfo  itemInfo = GameManager.GetInstance().ItemManager.GetItemInfo(eItemKind);
        this.itemInfo = itemInfo;
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
            this.itemInfo = itemInfo;
            imgIcon.sprite = Resources.Load<Sprite>("Icon/" + itemInfo.icon);
            textName.text = itemInfo.name;
            Button button = GetComponent<Button>();
            GameObject objTarget = GameManager.GetInstance().responnerPlayer.objPlayer;
            button.onClick.AddListener(() => EventItemButton(objTarget, itemInfo));
        }
        else
            Debug.LogError("GUIItemButton Set("+itemInfo.name+") Faild!!");
    }

    public void EventItemButton(GameObject obj, ItemInfo itemInfo)
    {
        if (Item.Use(obj, itemInfo))
        {
            GUIItemInventory guiItemInventory = GameManager.GetInstance().guiItemInventory;
            Iventory iventory = obj.GetComponent<Iventory>();
            iventory.RemoveItem(itemInfo);
        }

    }

    public void OnPointerExit(PointerEventData eventData)
    {
        GameManager.GetInstance().guiItemPopup.gameObject.SetActive(false);
    }

    public void OnPointerEnter(PointerEventData eventData)
    {
        GameManager.GetInstance().guiItemPopup.gameObject.SetActive(true);
        GameManager.GetInstance().guiItemPopup.Set(itemInfo);
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
