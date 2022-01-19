using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower;
    public Rigidbody2D rigidbody;
    public bool isGround;

    // Start is called before the first frame update
    void Start()
    {
        rigidbody = this.gameObject.GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Time.deltaTime;
      
        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Time.deltaTime;

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
}
