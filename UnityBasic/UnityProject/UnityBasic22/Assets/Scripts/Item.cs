using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public int Score;

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log(gameObject.name+ "-OnTriggerEnter2D:"+collision.gameObject.name);
        GameObject objPlayer = collision.gameObject;
        GameObject objItem = this.gameObject;

        Dynamic dynamic = objPlayer.GetComponent<Dynamic>();
       
        if(dynamic != null)
        {
            dynamic.Score += this.Score;
            Destroy(objItem);
        }
    }
}
