using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower;
    public float Speed = 1.5f;
    public Rigidbody2D rigidbody;
    public bool isGround;
    public int Score;

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 20), "Score:" + Score);
    }

    // Start is called before the first frame update
    void Start()
    {
        rigidbody = this.gameObject.GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Speed * Time.deltaTime;
      
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Speed * Time.deltaTime;

        //if (Input.GetKey(KeyCode.Space))
        //    transform.position += Vector3.up * 3 * Time.deltaTime;

        //플레이어가 땅에 닿았을때 점프가 가능하게한다.
        //땅에 닿았을때 변수를 참으로 설정하고,
        //점프키를 누를때 변수를 거짓으로 설정한다.
        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (isGround == true)
            {
                rigidbody.AddForce(Vector3.up * JumpPower);
                isGround = false;
            }
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isGround = true;
       
        Debug.Log("OnCollisionEnter2D:"+collision.gameObject.name);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        //if (collision.gameObject.name == "cherry")
        if (collision.gameObject.tag == "Item")
        {
            Score++;
            Destroy(collision.gameObject);
        }
    }
}
