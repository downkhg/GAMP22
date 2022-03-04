using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower;
    public float Speed = 1.5f;
    public Rigidbody2D rigidbody;
    public bool isGround;
    public bool isLoader;
    public int Score;
    public Gun gun;
    public Vector3 vDir;
    
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
        if (Input.GetKeyDown(KeyCode.X))
        {
            gun.Shot(vDir, GetComponent<Player>());
        }

        if(Input.GetKeyDown(KeyCode.Z))
        {
            CircleCollider2D circleCollider = GetComponent<CircleCollider2D>();
            Vector2 vPos = this.transform.position;
            Vector2 vCenter = vPos + circleCollider.offset;
            int nLayer = 1 << LayerMask.NameToLayer("Object");
            Collider2D collider = 
                Physics2D.OverlapCircle(vCenter, circleCollider.radius, nLayer);
            if(collider)
                GameManager.GetInstance().SetGUIStatus(GameManager.E_GUI_STATUS.THEEND);
        }

        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.position += Vector3.right * Speed * Time.deltaTime;
            //transform.Rotate(Vector3.zero);
            transform.localRotation = Quaternion.Euler(Vector3.zero);
            vDir = Vector3.right;
        }

        if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.position += Vector3.left * Speed * Time.deltaTime;
            //transform.Rotate(Vector3.up * 180);
            transform.localRotation = Quaternion.Euler(Vector3.up * 180);
            vDir = Vector3.left;
        }


        if (isLoader)
        {
            if (Input.GetKey(KeyCode.DownArrow))
                transform.position += Vector3.down * Speed * Time.deltaTime;

            if (Input.GetKey(KeyCode.UpArrow))
                transform.position += Vector3.up * Speed * Time.deltaTime;
        }

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
       
        //Debug.Log("OnCollisionEnter2D:"+collision.gameObject.name);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        //if (collision.gameObject.name == "cherry")
        if (collision.gameObject.tag == "Item")
        {
            Score++;
            Destroy(collision.gameObject);
        }
        if (collision.gameObject.name == "Loader")
        {
            isLoader = true;
            rigidbody.gravityScale = 0;
            rigidbody.velocity = Vector2.zero;
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.name == "Loader")
        {
            isLoader = false;
            rigidbody.gravityScale = 1;
            rigidbody.velocity = Vector2.zero;
        }
    }
}
