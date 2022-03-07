using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public string prefabName;
    public float Time;
    public bool isRespon;
    public int Life = -1;

    IEnumerator ProcessTimmer()
    {
        Debug.Log("ProcessTimmer 1");
        isRespon = true;
        yield return new WaitForSeconds(Time);
        ResponObject(prefabName);
        isRespon = false;
        Debug.Log("ProcessTimmer 2");
    }

    public void ResponObject(string name)
    {
        GameObject prefab = Resources.Load("Prefabs/" + name) as GameObject;
        GameObject copy = Instantiate(prefab);
        copy.transform.position = this.transform.position;
        copy.name = prefab.name;
        objPlayer = copy;
    }

    // Start is called before the first frame update
    void Start()
    {
        prefabName = objPlayer.name;
    }

    // Update is called once per frame
    void Update()
    {
        if(objPlayer == null && isRespon == false)
        {
            if (Life == -1)
            {
                StartCoroutine(ProcessTimmer());
            }
            else if (Life > 0)
            {
                StartCoroutine(ProcessTimmer());
                Life--;
            }
            //ResponObject(prefabName);
        }
    }
}
