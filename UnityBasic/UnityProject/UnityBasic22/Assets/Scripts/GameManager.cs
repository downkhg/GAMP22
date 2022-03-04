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
    public enum E_GUI_STATUS { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUI_STATUS curGUIStatus;
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
                if(responnerPlayer.objPlayer == null)
                    SetGUIStatus(E_GUI_STATUS.GAMEOVER);
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

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        UpdateGUIStatus();
    }

}
