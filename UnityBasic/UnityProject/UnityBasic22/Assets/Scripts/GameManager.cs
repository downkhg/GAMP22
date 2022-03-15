using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public Responner responnerEagle;
    public Responner responnerOpposum;
    public Responner responnerPlayer;
    public CameraTracker cameraTracker;

    public List<GameObject> listGUIScene;
    public GUIPlayerInfo guiPlayerInfo;

    public ItemManager ItemManager;

    public enum E_GUI_STATUS { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUI_STATUS curGUIStatus;

    public GameObject objPopupLayer;
    public GUIItemInventory guiItemInventory;

    public void UpdatePopupLayer()
    {
        if (objPopupLayer.activeSelf)
        {
            GameObject objPlayer = responnerPlayer.objPlayer;
            if (objPlayer)
            {
                Iventory iventory = objPlayer.GetComponent<Iventory>();
                if (iventory.itemInfos.Count != guiItemInventory.listItemButton.Count)
                {
                    guiItemInventory.RomoveButtons();
                    guiItemInventory.SetIventory(iventory);
                }
            }
        }
    }

    public bool ShowPopupLayer()
    {
        if(objPopupLayer.activeSelf)
        {
            guiItemInventory.RomoveButtons();
            objPopupLayer.SetActive(false);
            Time.timeScale = 1;
        }
        else
        {
            objPopupLayer.SetActive(true);
            GameObject objPlayer = responnerPlayer.objPlayer;
            if (objPlayer)
                guiItemInventory.SetIventory(objPlayer.GetComponent<Iventory>());
            Time.timeScale = 0;
        }

        return false;
    }

    void ShowGUIScene(E_GUI_STATUS state)
    {
        for(int i = 0; i< listGUIScene.Count; i++)
        {
            if(i == (int)state)
                listGUIScene[i].SetActive(true);
            else
                listGUIScene[i].SetActive(false);
        }
    }
    public void SetGUIStatus(E_GUI_STATUS status)
    {
        switch (status)
        {
            case E_GUI_STATUS.TITLE:
                
                Time.timeScale = 0;
                break;
            case E_GUI_STATUS.THEEND:
                Time.timeScale = 0;
                break;
            case E_GUI_STATUS.GAMEOVER:
                Time.timeScale = 0;
                break;
            case E_GUI_STATUS.PLAY:
                EventShowMeTheItem(11);
                responnerPlayer.Life = 3;
                Time.timeScale = 1;
                break;
        }
        ShowGUIScene(status);
        curGUIStatus = status;
    }
    public void UpdateGUIStatus()
    {
        switch (curGUIStatus)
        {
            case E_GUI_STATUS.TITLE:

                break;
            case E_GUI_STATUS.THEEND:
                break;
            case E_GUI_STATUS.GAMEOVER:
                break;
            case E_GUI_STATUS.PLAY:
                ResponEagleProcess();
                CameraTrackerTargetSettingProcess();
                guiPlayerInfo.Set(responnerPlayer.objPlayer);
                if(responnerPlayer.Life == 0)
                    SetGUIStatus(E_GUI_STATUS.GAMEOVER);
                if(Input.GetKeyDown(KeyCode.I))
                {
                    ShowPopupLayer();
                }
                break;
        }
    }
    void ResponEagleProcess()
    {
        if (responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();
            eagle.objResponPoint = responnerEagle.gameObject;
            eagle.objPatrolPoint = responnerOpposum.gameObject;
        }
    }
    void CameraTrackerTargetSettingProcess()
    {

        if (cameraTracker.objTarget == null)
        {
            cameraTracker.objTarget = responnerPlayer.objPlayer;
        }
    }

    private void Awake()
    {
        instance = this;
        ItemManager = GetComponent<ItemManager>();
        SetGUIStatus(curGUIStatus);
    }

    static GameManager instance;

    public static GameManager GetInstance()
    {
        return instance;
    }

    public void EventChangeScene(int sceneidx)
    {
        SetGUIStatus((E_GUI_STATUS)sceneidx);
    }

    public void EventShowMeTheItem(int count)
    {
        if(responnerPlayer.objPlayer)
        {
            Iventory iventory = responnerPlayer.objPlayer.GetComponent<Iventory>();
            for (int i = 0; i < count; i++)
            {
                iventory.SetIventory(Item.E_ITEM_KIND.SUPER);
                iventory.SetIventory(Item.E_ITEM_KIND.CHERRY);
                iventory.SetIventory(Item.E_ITEM_KIND.GEM);
                iventory.SetIventory(Item.E_ITEM_KIND.BULLET);
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
        UpdateGUIStatus();
        UpdatePopupLayer();
    }

}
