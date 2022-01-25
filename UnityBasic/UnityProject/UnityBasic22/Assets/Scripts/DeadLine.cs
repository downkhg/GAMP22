using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeadLine : MonoBehaviour
{
    public float DeadY = -2;
    // Update is called once per frame
    void Update()
    {
        if(transform.position.y < DeadY)
        {
            Destroy(this.gameObject);
        }
        //디버그용 코드가없다고 실행에 지장이 되진않음.
        Vector3 vPos = transform.position;
        Vector3 vDeadPos = vPos;
        vDeadPos.y = DeadY;
        float lineDist = 1000;
        Vector3 vLineStart = vDeadPos + Vector3.left * lineDist;
        Vector3 vLineEnd = vDeadPos + Vector3.right * lineDist;
        Debug.DrawLine(vLineStart, vLineEnd, Color.red) ;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.name == "DeadZone")
        {
            Destroy(this.gameObject);
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.name == "DeadZone")
        {
            Destroy(this.gameObject);
        }
    }
}
