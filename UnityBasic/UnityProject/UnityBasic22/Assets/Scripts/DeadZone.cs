using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeadZone : MonoBehaviour
{
    //여기서 처리는 가능하지만 낙사 이외에 죽음에 대해서는 처리할수없다.
    public void ResponObject(GameObject obj)
    {
        GameObject prefab = Resources.Load("Prefabs/" + obj.name) as GameObject;
        GameObject copy = Instantiate(prefab);
        copy.name = prefab.name;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Destroy(collision.gameObject);
        //ResponObject(collision.gameObject);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        Destroy(collision.gameObject);
        //ResponObject(collision.gameObject);
    }
}
