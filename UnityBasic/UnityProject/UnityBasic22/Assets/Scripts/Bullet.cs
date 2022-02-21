using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public Vector3 vStartPos;
    public float dist;
    public Player master;

    // Start is called before the first frame update
    void Start()
    {
        //Destroy(this.gameObject,1);
        vStartPos = this.transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vPos = this.transform.position;
        float fDist = Vector3.Distance(vStartPos, vPos);

        if(fDist >= dist)
        {
            Destroy(this.gameObject);
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Monster")
        {
            SuperMode superMode = collision.GetComponent<SuperMode>();
            if (superMode != null && superMode.isUse == false)
            {
                //Player me = GameObject.Find("player").GetComponent<Player>();
                //Player me = GameManager.GetInstance().responnerPlayer.objPlayer.GetComponent<Player>();
                Player me = master;
                Player target = collision.gameObject.GetComponent<Player>();
                me.Attack(target);
                superMode.Active();
            }
            Destroy(this.gameObject);
        }
    }
}
