using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GUIStatusBar : MonoBehaviour
{
    public RectTransform recttrStatus;
    public RectTransform recttrBackGround;

    public void SetStatus(float cur, float max)
    {
        float rat = cur / max;
        Vector2 vStatusSize = recttrStatus.sizeDelta;
        vStatusSize.x = recttrBackGround.sizeDelta.x * rat;
        recttrStatus.sizeDelta = vStatusSize;
        //recttrStatus.sizeDelta.x = recttrBackGround.sizeDelta.x * rat;
    }

    // Start is called before the first frame update
    void Start()
    {
        SetStatus(20, 100);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
