using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject objBullet;
    public float ShotPower;

    public void Shot(Vector3 dir)
    {
        GameObject copyBullet = Instantiate(objBullet);
        copyBullet.transform.position = this.transform.position;
        Rigidbody2D rigidbody = copyBullet.GetComponent<Rigidbody2D>();
        if (rigidbody != null)
        {
            //로컬좌표에서 방향을 가져오므로, 총알이 바라보는 방향으로 발사된다.
            //rigidbody.AddForce(transform.right * ShotPower);
            rigidbody.AddForce(dir * ShotPower);
        }
        else
            Debug.LogError(objBullet.gameObject.name + "is not Rigidbody2D");
    }

    // Update is called once per frame
    void Update()
    {
      
    }
}
