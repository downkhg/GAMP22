using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemInventory : MonoBehaviour
{
    public List<GUIItemButton> listItemButton;
    public RectTransform recttrContent;

    public void SetIventory(Iventory iventory)
    {
        GameObject prefabButton = Resources.Load("GUI/ItemButton") as GameObject;
        foreach(ItemInfo item in iventory.itemInfos)
        {
            GameObject objButton = Instantiate(prefabButton, recttrContent.transform);
            GUIItemButton guiItemButton = objButton.GetComponent<GUIItemButton>();
            guiItemButton.Set(item);
            listItemButton.Add(guiItemButton);
        }
        ResizeContent();
    }

    public void RomoveButtons()
    {
        foreach (GUIItemButton guiItemButton in listItemButton)
        {
            Destroy(guiItemButton.gameObject);
        }
        listItemButton.Clear();
    }

    public void ResizeContent()
    {
        GridLayoutGroup gridLayoutGroup = recttrContent.GetComponent<GridLayoutGroup>();
        if(gridLayoutGroup)
        {
            Vector2 vContentSize = recttrContent.sizeDelta;
            Vector2 vButtonSize = gridLayoutGroup.cellSize;
            int nCol = (int)(vContentSize.x / vButtonSize.x);
            int nRow = listItemButton.Count / nCol;
            if (listItemButton.Count % nCol > 0) nRow++;
            vContentSize.y = nRow * vButtonSize.y;
            recttrContent.sizeDelta = vContentSize;
        }
    }

    //// 테스트
    //void Start()
    //{
    //    GameObject objPlayer = GameManager.GetInstance().responnerPlayer.objPlayer;

    //    if(objPlayer)
    //    {
    //        Iventory inventory = objPlayer.GetComponent<Iventory>();
    //        SetIventory(inventory);
    //    }
    //}

    // Update is called once per frame
    void Update()
    {
        
    }
}
