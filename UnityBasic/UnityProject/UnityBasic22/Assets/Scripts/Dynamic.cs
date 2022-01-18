using UnityEngine;

public class Dynamic : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Time.deltaTime;
      
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Time.deltaTime;

        if (Input.GetKey(KeyCode.UpArrow))
            transform.position += Vector3.up * Time.deltaTime;

        if (Input.GetKey(KeyCode.DownArrow))
            transform.position += Vector3.down * Time.deltaTime;
    }
}
