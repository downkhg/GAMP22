using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SuperMode : MonoBehaviour
{
    public bool isUse;
    public float Time;
    public SpriteRenderer spriteRenderer;

    IEnumerator ProcessTimmer()
    {
        isUse = true;
        yield return new WaitForSeconds(Time);
        isUse = false;
        spriteRenderer.color = Color.white;
    }

    public void Active()
    {
        StartCoroutine(ProcessTimmer());
    }

    // Start is called before the first frame update
    void Start()
    {
        spriteRenderer = GetComponent<SpriteRenderer>();
        if (isUse) Active();
    }

    // Update is called once per frame
    void Update()
    {
        if(isUse)
        {
            Color color = spriteRenderer.color;
            if (color.a == 1) color.a = 0;
            else color.a = 1;
            spriteRenderer.color = color;
        }
    }
}
