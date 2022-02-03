using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public string prefabName;

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
        if(objPlayer == null)
        {
            ResponObject(prefabName);
        }
    }
}
