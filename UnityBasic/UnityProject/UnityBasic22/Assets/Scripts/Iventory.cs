using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Iventory : MonoBehaviour
{
    public List<ItemInfo> itemInfos;

    public ItemInfo GetItem(Item.E_ITEM_KIND item)
    {
        return itemInfos.Find(x => x.item_eff == item);
    }

    public void SetIventory(Item.E_ITEM_KIND item)
    {
        itemInfos.Add(GameManager.GetInstance().ItemManager.GetItemInfo(item));
    }

    public void RemoveItem(Item.E_ITEM_KIND item)
    {
        itemInfos.Remove(GameManager.GetInstance().ItemManager.GetItemInfo(item));
    }

    public void RemoveItem(ItemInfo iteminfo)
    {
        itemInfos.Remove(iteminfo);
    }

    private void OnGUI()
    {
        int w = 100, h = 20;

        for(int i = 0; i< itemInfos.Count; i++)
        {
            if( GUI.Button(new Rect(0, h*i, w, h), itemInfos[i].name))
            {
                Item.Use(this.gameObject, itemInfos[i]);
                itemInfos.Remove(itemInfos[i]);
            }
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
