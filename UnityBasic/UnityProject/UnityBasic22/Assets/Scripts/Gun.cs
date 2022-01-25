using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Gun : MonoBehaviour
{
    public GameObject objBullet;
    public float ShotPower;

    void Shot()
    {
        Rigidbody2D rigidbody = objBullet.GetComponent<Rigidbody2D>();
        if (rigidbody != null)
            rigidbody.AddForce(Vector3.right * ShotPower);
        else
            Debug.LogError(objBullet.gameObject.name + "is not Rigidbody2D");
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.X))
        {
            Shot();
        }
    }
}
